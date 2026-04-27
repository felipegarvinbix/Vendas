/****************************************************************************************************************************************
	File:		T_FATO_PEDIDOS.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: leitura das tabelas finais da aplicação + variáveis de cálculos.
	
****************************************************************************************************************************************/

SET HidePrefix = '%';

Pedidos:
LOAD
    KEY_PEDIDO                      AS %PEDIDO, 
    KEY_CLIENTE                     AS %CLIENTE, 
    KEY_FUNCIONARIO                 AS %FUNCIONARIO, 
    DAT_DATA_PEDIDO                 AS "Data Pedido", 
    DAT_DATA_ENVIO                  AS "Data Envio", 
    QTD_DIAS_PEDIDO                 AS "Dias Pedido",
    FLG_NO_PRAZO                    AS %NO_PRAZO,
    FLG_BACKLOG                     AS %BACKLOG, 
    KEY_EXPEDIDOR                   AS %EXPEDIDOR, 
    VLR_VALOR_FRETE                 AS "Valor Frete", 
    DES_NOME_ENVIO                  AS "Empresa Destino", 
    DES_CIDADE_ENVIO                AS "Destino", 
    DES_PAIS_ENVIO                  AS "País Destino", 
    KEY_CALENDARIO                  AS %CALENDARIO, 
    KEY_PRODUTO                     AS %PRODUTO, 
    VLR_VALOR_PEDIDO                AS "Valor Pedido", 
    VLR_PRECO_UNITARIO              AS "Preço Unitário", 
    QTD_QUANTIDADE                  AS "Itens Pedido", 
    VLR_DESCONTO                    AS "Desconto"
FROM $(vDadosQVD)T_FATO_PEDIDOS.qvd (qvd);

Calendario:
LOAD 
    KEY_CALENDARIO                  AS %CALENDARIO, 
    DAT_DATA                        AS "Data", 
    DES_TIPO_DATA                   AS %TIPO_DATA, 
    NUM_ANO                         AS "Ano", 
    DES_MÊS                         AS "Mês", 
    NUM_DIA                         AS "Dia",
    NUM_ANOMÊS                      AS %ANO_MES,
    DES_ANOMÊS                      AS "Ano Mês"
FROM $(vDadosQVD)T_DIM_CALENDARIO.qvd (qvd);

Clientes:
LOAD 
    KEY_CLIENTE                     AS %CLIENTE, 
    DES_EMPRESA_CLIENTE             AS "Empresa Cliente", 
    DES_CLIENTE                     AS "Cliente", 
    DES_CARGO_CLIENTE               AS "Cargo Cliente", 
    DES_CIDADE_CLIENTE              AS "Cidade Cliente", 
    DES_PAIS_CLIENTE                AS "País Cliente"
FROM $(vDadosQVD)T_DIM_CLIENTES.qvd (qvd);

Expedidores:
LOAD 
    KEY_EXPEDIDOR                   AS %EXPEDIDOR, 
    DES_EXPEDIDOR                   AS "Expedidor"
FROM $(vDadosQVD)T_DIM_EXPEDIDORES.qvd (qvd);

Funcionarios:
LOAD 
    KEY_FUNCIONARIO                 AS %FUNCIONARIO, 
    DES_FUNCIONARIO                 AS "Funcionário",
    DES_PRIMEIRO_NOME_FUNCIONARIO   AS "Primeiro Nome Funcionário",
    KEY_SUPERVISOR                  AS %SUPERVISOR, 
    DES_SUPERVISOR                  AS "Supervisor", 
    DES_CARGO                       AS "Cargo Funcionário", 
    DES_CIDADE_FUNCIONARIO          AS "Cidade Funcionário", 
    DES_PAIS_FUNCIONARIO            AS "País Funcionário"
FROM $(vDadosQVD)T_DIM_FUNCIONARIOS.qvd (qvd);

Produtos:
LOAD 
    KEY_PRODUTO                     AS %PRODUTO, 
    DES_PRODUTO_NOME                AS "Produto", 
    DES_FORNECEDOR                  AS "Fornecedor", 
    DES_CATEGORIA                   AS "Categoria", 
    QTD_UNIDADES_NO_ESTOQUE         AS "Unidades Estoque",
    QTD_UNIDADES_EM_PROCESSAMENTO   AS "Unidades Processamento",
    VLR_TOTAL_ESTOQUE               AS "Valor Total Estoque", 
    FLG_ESTOQUE_MINIMO              AS %ESTOQUE_MINIMO,
    QTD_ESTOQUE_MINIMO              AS "Estoque Mínimo",
    FLG_PRODUTO_DESCONTINUADO       AS "Produto Ativo"
FROM $(vDadosQVD)T_DIM_PRODUTOS.qvd (qvd);