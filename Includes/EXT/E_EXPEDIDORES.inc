/****************************************************************************************************************************************
	File:		E_EXPEDIDORES.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Leitura da tabela de expedidores onde contém as empresas que fazem a expedição dos produtos.
	
****************************************************************************************************************************************/

Expedidores:
LOAD
    shipper_id,
    company_name
FROM $(vDadosBase)northwind_xls.xlsx 
(ooxml, embedded labels, table is shippers);

STORE Expedidores INTO $(vDadosQVD)E_EXPEDIDORES.qvd (qvd);
DROP TABLE Expedidores;