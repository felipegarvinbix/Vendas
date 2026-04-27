/****************************************************************************************************************************************
	File:		E_FORNECEDORES.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Leitura da tabela de fornecedores onde contém os fornecedores da empresa.
	
****************************************************************************************************************************************/

Fornecedores:
LOAD
    supplier_id,
    company_name,
    contact_name,
    contact_title,
    address,
    city,
    region,
    country
FROM $(vDadosBase)northwind_xls.xlsx 
(ooxml, embedded labels, table is suppliers);

STORE Fornecedores INTO $(vDadosQVD)E_FORNECEDORES.qvd (qvd);
DROP TABLE Fornecedores;

