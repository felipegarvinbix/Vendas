
// ********************************************************************************
//   Criação de variáveis globais utilizadas pelas aplicações.
// ********************************************************************************
//
// Variáveis globais para identificar os diretórios de leitura e gravação dos dados.
//

//////////////////////////////////////
//**      Variaveis de caminho    **//
//////////////////////////////////////

SET vDados              = lib://Google_Drive - felipe.garvin@bix-tech.com;
SET vDadosBase          = $(vDados)/14gCpcD77dYeqVT5bm3P-qJ4KLh_M6sTn/;
SET vDadosExtraidos     = $(vDados)/14Zw81bjyYEDm5UP80GqagnWk4B4p3WCb/;
SET vDadosProcessados   = $(vDados)/14RRjSG8C4O1dnR6Gpqdml_mlv2SxWW8b/;
SET vDadosCarregamento  = $(vDados)/14WUhUT1Z44q6b20lICXGfRAfpwFL51IF/;
SET vDadosQVD           = $(vDados)/13CTTMxoJf9ajBLXM_CG6rM80Sbw7wxtU/;

//////////////////////////////////////
//**      Variaveis de cor        **//
//////////////////////////////////////

SET vColor_Officina     = rgb(0, 37, 84); //HEX:002554
SET vColor_Vermelho     = rgb(192, 57, 43); // HEX:c0392b
SET vColor_Cinza        = rgb(149, 165, 166);
SET vColor_Preto        = rgb(0, 0, 0);
SET vColor_Branco       = rgb(236, 240, 241);
SET vColor_Marrom       = rgb(222, 184, 135);
SET vColor_Laranja      = rgb(230, 126, 34); // HEX:e67e22
SET vColor_Amarelo      = rgb(241, 196, 15); // HEX:f1c40f
SET vColor_Azul         = rgb(41, 128, 185); // HEX:2980b9
SET vColor_Roxo         = rgb(155, 89, 182);
SET vColor_Verde        = rgb(46, 204, 113); // HEX: 2ecc71

///////////////////////////////////////
//** 		Default Selection 	   **//
///////////////////////////////////////

LET vInitialLoad        = Now();
LET vYear_Today         = year(date(today()-1));
LET vMonth_Today        = month(date(today()-1));
LET vDay_Today          = day(date(today()-1));
LET vWeek_Today         = week(date(today()-1));
LET VCompReferencia     = date(MonthStart(today()-1),'MM_YYYY');
LET VCompFuncionarios   = date(MonthStart(today()),'MM_YYYY');
LET vDiaData            = day(today());
LET vAnoHeadcount       = year(date(today()));
LET vDataReferencia     = MonthStart(today());



