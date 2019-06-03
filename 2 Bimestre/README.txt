TEORIA DE GRAFOS
Trabalho da Disciplina: Implementac¸a~o de algoritmos em grafos
APRESENTAC¸A~O:
Desenvolvimento de um programa computacional que realize a leitura de uma topologia de rede e execute o seguinte algoritmo de otimizac¸a~o de fluxo em redes Ford Fulkerson.
O co´digo pode ser escrito nas seguintes linguagens de programac¸a~o em C ou C++.
O trabalho pode ser desenvolvido em dupla e sera´ apresentado em sala de aula a sua compilac¸a~o e execuc¸a~o de alguns casos de teste para a validac¸a~o dos resultados.
O aluno deve obrigatoriamente enviar o co´digo fonte para o email (alexandre.augusto.souza@alumni.usp.br) para confere^ncia de pla´gios. Observando pla´gio, os alunos sera~o comunicados e tera~o suas notas reduzidas.
O programa devera´ realizar a execuc¸a~o da seguinte forma:
1.
2. 3.
Realizar a leitura de um arquivo txt com a topologia de rede a ser testada, conforme descric¸a~o contida neste documento;
Selecionado um ve´rtice inicial para ana´lise da rede;
Apresentar o resultado do fluxo total que pode ser transportado na rede.
Arquivo de topologia devera´ ser no formato txt com os seguintes campos separados com ponto e vi´rgula: aresta inicial, final e capacidade da aresta. O exemplo abaixo mostra a topologia a ser lida para o processamento dos algoritmos.
ArestaInicial;ArestaFinal;CapacidadeAresta 1;2;20