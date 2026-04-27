
/*
 * Biblioteca de funções/subrotinas transversais no ambiente Qlik Sense
 *  (são utilizadas em mais de uma aplicação)
 */

//-----------------------------------------------------------------------------------------------
//     Função  : TratarExpansaoMacro                                                            
//   Objetivo  : Permite chamada recursiva de variável sem calculo forçado
//                  (substitui '@' por '$' no conteudo da variavel)
// Criado Por  : BIX                                   
//-----------------------------------------------------------------------------------------------
SUB TratarExpansaoMacro(vNomeVariavel)
	LET vNomeVariavel = Text(Replace(vNomeVariavel, '@', '$'));
END SUB;
//-----------------------------------------------------------------------------------------------

/*
 * Variáveis para os cálculos relacionados a datas
 */

SET vMaior_Ano = // variável para definir o maior ano
				Max(Ano);  
CALL TratarExpansaoMacro(vMaior_Ano);

SET vMaior_Ano_1 = // variável para definir o segundo maior ano 
				Max(Ano)-1; 
CALL TratarExpansaoMacro(vMaior_Ano_1);

SET vQuantidadeDias = // variável para definir a quantidade de dias
				COUNT(DISTINCT [Dia]); 
CALL TratarExpansaoMacro(vQuantidadeDias);

SET vQuantidadeAnoMes = // variável para definir a quantidade de ano mês 
				COUNT(DISTINCT [Ano Mês]); 
CALL TratarExpansaoMacro(vQuantidadeAnoMes);

SET vQuantidadeAno = // variável para definir a quantidade de ano
				COUNT(DISTINCT Ano); 
CALL TratarExpansaoMacro(vQuantidadeAno);

/*
 * Variáveis para os cálculos em geral
 */

SET vTotalVendas = // variável para calcular a quantidade total de vendas
					COUNT(DISTINCT {< %TIPO_DATA = {'Data Pedido'} >} [%PEDIDO]);
CALL TratarExpansaoMacro(vTotalVendas);

SET vTotalItens = // variável para calcular a quantidade total de itens da venda
					COUNT({< %TIPO_DATA = {'Data Pedido'} >} [%PEDIDO]);
CALL TratarExpansaoMacro(vTotalItens);

SET vValorVendas = // variável para calcular o valor das vendas
					SUM( {< %TIPO_DATA = {'Data Pedido'} >} [Valor Pedido]);
CALL TratarExpansaoMacro(vValorVendas);

SET vBacklog = // variável para calcular o backlog (vendas em aberto)
					COUNT(DISTINCT {< %TIPO_DATA = {'Data Pedido'}, [%BACKLOG] = {'1'} >} [%PEDIDO]);
CALL TratarExpansaoMacro(vBacklog);

SET vTempoMedio = // variável para calcular o tempo médio das vendas
					AVG( {< %TIPO_DATA = {'Data Pedido'} >} [Dias Pedido]);
CALL TratarExpansaoMacro(vTempoMedio);

SET vPrazoDeVendas = 	// variável para calcular se a venda foi feita no prazo ou fora do prazo
				(
					COUNT(DISTINCT {< %TIPO_DATA = {'Data Pedido'}, [%NO_PRAZO] = {'1'} >} [%PEDIDO])
					/
					COUNT(DISTINCT {< %TIPO_DATA = {'Data Pedido'} >} [%PEDIDO])
				);
CALL TratarExpansaoMacro(vPrazoDeVendas);

SET vUnidadesEstoque = // variável para calcular a quantidade de unidades dos produtos no estoque
					SUM([Unidades Estoque]);
CALL TratarExpansaoMacro(vUnidadesEstoque);

SET vEstoqueMinimo = // variável para calcular a quantidade mínima de unidades dos produtos no estoque
					SUM([Estoque Mínimo]);
CALL TratarExpansaoMacro(vEstoqueMinimo);

SET vUnidadesProcessadas = // variável para calcular a quantidade de produtos em processamento
					SUM([Unidades Processamento]);
CALL TratarExpansaoMacro(vUnidadesProcessadas);

SET vClientes = // variável para calcular a quantidade de clientes
					COUNT(DISTINCT {<%TIPO_DATA = {'Data Pedido'} >} %CLIENTE);
CALL TratarExpansaoMacro(vClientes);

SET vFuncionarios = // variável para calcular a quantidade de vendedores
					COUNT(DISTINCT %FUNCIONARIO);
CALL TratarExpansaoMacro(vFuncionarios);

SET vTicketMedio = 	// variável para calcular o ticket médio (valor de vendas pela quantidade de clientes)
					@(vValorVendas) 
					/ 
					@(vClientes) ;
CALL TratarExpansaoMacro(vTicketMedio);

SET vMetaValorFaturado = // variável para calcular a meta do valor de vendas (utiliza o GETFIELDSELECTIONS porque caso filtrado o mês, o gráfico abre a informação de valor por dia e ai é necessário alterar o cálculo)
					IF(GetFieldSelections([Ano Mês]) > 0 
						OR (GetFieldSelections([Mês]) > 0 AND GetFieldSelections([Ano]) > 0),
							(
								@(vValorVendas)
    							/ 
    							@(vQuantidadeDias)
 							), 
							(
								@(vValorVendas)
    							/ 
    							@(vQuantidadeAnoMes)
 							) 
					);
CALL TratarExpansaoMacro(vMetaValorFaturado);

SET vVerificarEstoqueMinimo = ONLY(%ESTOQUE_MINIMO);
CALL TratarExpansaoMacro(vVerificarEstoqueMinimo);

SET vMetaFuncionario = // variável para calcular a meta de venda dos funcionários, é realizado uma media em cima do valor de vendas
					(
						SUM(TOTAL {< %TIPO_DATA = {'Data Pedido'}, [Funcionário] = , [Primeiro Nome Funcionário] = >} [Valor Pedido])
						/ 
						COUNT(TOTAL DISTINCT {< [Funcionário] = , [Primeiro Nome Funcionário] = >} %FUNCIONARIO)
 					);
CALL TratarExpansaoMacro(vMetaFuncionario);
						
SET vProdutos = // variável para calcular a quantidade distinta de produtos
				COUNT(DISTINCT %PRODUTO);
CALL TratarExpansaoMacro(vProdutos);
    
SET vValorEstoque = // variável para calcular o valor total de estoque
				SUM([Valor Total Estoque]);
CALL TratarExpansaoMacro(vValorEstoque);

/*
 * Variáveis para os cálculos de cor
 */

SET vCorMetaValorFaturado_1 = // variável para calcular a cor da meta do valor de vendas, verde ou vermelho, caso não tenha sido filtrado nada no BI
				IF(
					SUM(AGGR(SUM( {< %TIPO_DATA = {'Data Pedido'} >} [Valor Pedido]), [Ano Mês]))
					>=    
    				SUM(TOTAL {< %TIPO_DATA = {'Data Pedido'} >} [Valor Pedido])
					/
					COUNT(DISTINCT TOTAL [Ano Mês]), @(vColor_Verde), @(vColor_Vermelho) 
				);
CALL TratarExpansaoMacro(vCorMetaValorFaturado_1);

SET vCorMetaValorFaturado_2 = // variável para calcular a cor da meta do valor de vendas, verde ou vermelho, caso tenha sido filtrado no BI o mês e ai necessário cálculo por dia
				IF(
					SUM(AGGR(SUM( {< %TIPO_DATA = {'Data Pedido'} >} [Valor Pedido]), [Dia]))
					>=
					SUM(TOTAL {< %TIPO_DATA = {'Data Pedido'} >} [Valor Pedido])
					/
					COUNT(TOTAL DISTINCT [Dia]), @(vColor_Verde), @(vColor_Vermelho) 
				);
CALL TratarExpansaoMacro(vCorMetaValorFaturado_2);

SET vCorMetaValorFaturado = // variável para calcular a cor do valor de vendas (utiliza o GETFIELDSELECTIONS porque caso filtrado o mês, o gráfico abre a informação de valor por dia e ai é necessário alterar o cálculo)
				IF(GetFieldSelections([Ano Mês]) > 0 
					OR (GetFieldSelections([Mês]) > 0 AND GetFieldSelections([Ano]) > 0),
						@(vCorMetaValorFaturado_2),
						@(vCorMetaValorFaturado_1)
				);
CALL TratarExpansaoMacro(vCorMetaValorFaturado);

SET vCorFundoEstoque = // variável para calcular a cor da tabela de controle de estoque
				IF(EVEN(ROWNO(TOTAL))=0,@(vColor_Marrom),@(vColor_Branco));
CALL TratarExpansaoMacro(vCorFundoEstoque);







