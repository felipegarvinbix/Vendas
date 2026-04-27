/****************************************************************************************************************************************
	File:		T_DIM_EXPEDIDORES.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Transformar a tabela E_EXPEDIDORES em uma tabela DIMENSÃO.
	
****************************************************************************************************************************************/

Expedidores:
LOAD
    shipper_id                              AS KEY_EXPEDIDOR,
    company_name                            AS DES_EXPEDIDOR
FROM $(vDadosQVD)E_EXPEDIDORES.qvd (qvd);
