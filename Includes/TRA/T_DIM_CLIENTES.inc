/****************************************************************************************************************************************
	File:		T_DIM_CLIENTES.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Transformar a tabela E_CLIENTES em uma tabela DIMENSÃO.
	
****************************************************************************************************************************************/

Clientes:
LOAD
    customer_id							            AS KEY_CLIENTE,
    company_name									AS DES_EMPRESA_CLIENTE,
    contact_name									AS DES_CLIENTE,
    contact_title									AS DES_CARGO_CLIENTE,							
    city											AS DES_CIDADE_CLIENTE,
    country											AS DES_PAIS_CLIENTE
FROM $(vDadosQVD)E_CLIENTES.qvd (qvd);


