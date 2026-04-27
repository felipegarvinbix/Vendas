/****************************************************************************************************************************************
	File:		T_FATO_PEDIDOS.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Transformar as tabelas E_PEDIDOS e E_DETALHE_PEDIDOS em uma tabela Fato.
	
****************************************************************************************************************************************/

Pedidos:
LOAD
    *,
    AUTONUMBERHASH128(DAT_DATA_PEDIDO, DAT_DATA_ENVIO)      AS KEY_CALENDARIO,
    DAT_DATA_ENVIO - DAT_DATA_PEDIDO                        AS QTD_DIAS_PEDIDO,
    IF(DAT_DATA_ENVIO - DAT_DATA_PEDIDO <= 10, 1, 0)        AS FLG_NO_PRAZO // cálculo para definir se a venda foi feita no prazo ou não, levando em consideração 10 dias de prazo máximo
;
LOAD
    order_id										        AS KEY_PEDIDO,
    customer_id							                    AS KEY_CLIENTE,
    employee_id										        AS KEY_FUNCIONARIO,
    DATE(DATE#(order_date, 'yyyy-MM-dd'),'dd/MM/yyyy')	    AS DAT_DATA_PEDIDO, 
    DATE(DATE#(shipped_date, 'yyyy-MM-dd'),'dd/MM/yyyy')    AS DAT_DATA_ENVIO, 
    IF(ISNULL(shipped_date), 1, 0)                          AS FLG_BACKLOG, // verifica se a venda está em aberto ou já foi fechada  
    ship_via										        AS KEY_EXPEDIDOR,
    NUM(freight,'#.##0,00')                                 AS VLR_VALOR_FRETE,
    ship_name										        AS DES_NOME_ENVIO,
    ship_city										        AS DES_CIDADE_ENVIO,
    ship_country									        AS DES_PAIS_ENVIO
FROM $(vDadosQVD)E_PEDIDOS.qvd (qvd);

LEFT JOIN (Pedidos)

LOAD
    order_id										        AS KEY_PEDIDO,
    product_id										        AS KEY_PRODUTO,  
    NUM(
        (
            ALT(NUM(unit_price,'#.##0,00'), 0)
            *
            ALT(quantity, 0)
        )
        - 
        (
            (
                ALT(NUM(unit_price,'#.##0,00'), 0)
                *
                ALT(quantity, 0)
            )   
            * ALT(NUM(discount,'#.##0,00'), 0)
        )
    )                                                       AS VLR_VALOR_PEDIDO, // cálculo para definir o valor de vendas, primeiro é multiplicado a quantidade de produtos da venda pelo preço unitário do produto e depois subtraí o desconto do produto caso tiver
    NUM(unit_price,'#.##0,00') 	                            AS VLR_PRECO_UNITARIO,
    quantity										        AS QTD_QUANTIDADE,
    NUM(discount,'#.##0,00') 	                            AS VLR_DESCONTO
FROM $(vDadosQVD)E_DETALHE_PEDIDOS.qvd (qvd);

