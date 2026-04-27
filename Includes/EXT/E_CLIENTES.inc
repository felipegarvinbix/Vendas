/****************************************************************************************************************************************
	File:		E_CLIENTES.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Leitura da tabela de clientes onde contém a listagem dos clientes da empresa.
	
****************************************************************************************************************************************/

Clientes:
LOAD
    customer_id,
    company_name,
    contact_name,
    contact_title,
    city,
    region,
    country
FROM $(vDadosBase)northwind_xls.xlsx 
(ooxml, embedded labels, table is customers);

STORE Clientes INTO $(vDadosQVD)E_CLIENTES.qvd (qvd);
DROP TABLE Clientes;


