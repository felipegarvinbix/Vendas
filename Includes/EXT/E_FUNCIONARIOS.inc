/****************************************************************************************************************************************
	File:		E_FUNCIONARIOS.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Leitura da tabela de funcionários onde contém os funcionários da empresa.
	
****************************************************************************************************************************************/

Funcionarios:
LOAD
    employee_id,
    last_name,
    first_name,
    title,
    birth_date,
    hire_date,
    reports_to,
    city,
    region,
    country
FROM $(vDadosBase)northwind_xls.xlsx 
(ooxml, embedded labels, table is employee);

STORE Funcionarios INTO $(vDadosQVD)E_FUNCIONARIOS.qvd (qvd);
DROP TABLE Funcionarios;


