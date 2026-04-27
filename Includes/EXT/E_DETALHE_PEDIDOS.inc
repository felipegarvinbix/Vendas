/****************************************************************************************************************************************
	File:		E_DETALHE_PEDIDOS.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Leitura da tabela de detalhe pedidos onde contém os detalhes dos pedidos.
	
****************************************************************************************************************************************/

Detalhe_Pedidos:
LOAD
    order_id,
    product_id,
    unit_price,
    quantity,
    discount
FROM $(vDadosBase)northwind_xls.xlsx 
(ooxml, embedded labels, table is order_details);

STORE Detalhe_Pedidos INTO $(vDadosQVD)E_DETALHE_PEDIDOS.qvd (qvd);
DROP TABLE Detalhe_Pedidos;

