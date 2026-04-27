/****************************************************************************************************************************************
	File:		E_PEDIDOS.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Leitura da tabela de pedidos onde contém as informações de pedidos da empresa.
	
****************************************************************************************************************************************/

Pedidos:
LOAD
    order_id,
    customer_id,
    employee_id,
    order_date,
    required_date,
    shipped_date,
    ship_via,
    freight,
    ship_name,
    ship_city,
    ship_region,
    ship_country
FROM $(vDadosBase)northwind_xls.xlsx 
(ooxml, embedded labels, table is orders);

STORE Pedidos INTO $(vDadosQVD)E_PEDIDOS.qvd (qvd);
DROP TABLE Pedidos;


