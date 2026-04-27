/****************************************************************************************************************************************
	File:		T_DIM_FUNCIONARIOS.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Transformar a tabela E_FUNCIONARIOS em uma tabela DIMENSÃO.
	
****************************************************************************************************************************************/

// Mapeamento necessário para descobrir qual o supervisor do funcionário
Mapa_Supervisor:
MAPPING LOAD   
    employee_id,
    first_name & ' ' & last_name
FROM $(vDadosQVD)E_FUNCIONARIOS.qvd (qvd);

Funcionario:
LOAD
    employee_id										        AS KEY_FUNCIONARIO,
    first_name & ' ' & last_name					        AS DES_FUNCIONARIO,
    first_name                                              AS DES_PRIMEIRO_NOME_FUNCIONARIO,
    reports_to                                              AS KEY_SUPERVISOR,                                                
    APPLYMAP('Mapa_Supervisor', reports_to, NULL())         AS DES_SUPERVISOR,
    title											        AS DES_CARGO,
    city											        AS DES_CIDADE_FUNCIONARIO,
    country											        AS DES_PAIS_FUNCIONARIO
FROM $(vDadosQVD)E_FUNCIONARIOS.qvd (qvd);