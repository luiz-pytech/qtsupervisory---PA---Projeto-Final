# Sistema Supervisório com Qt Creator (C++)

[![C++](https://img.shields.io/badge/C%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Qt](https://img.shields.io/badge/Qt-%2341CD52.svg?style=for-the-badge&logo=qt&logoColor=white)](https://www.qt.io/)
[![Status](https://img.shields.io/badge/Status-Concluido-green)](https://shields.io/)

Um sistema de supervisão desenvolvido em C++ utilizando o framework Qt Creator como projeto da disciplina de Programação Avançada. O projeto estabelece uma conexão entre um servidor, um consumidor e um produtor de dados, possibilitando um sistema básico de monitoramento.

---

[![Demonstração da Interface do QtSupervisory](https://github.com/luiz-pytech/qtsupervisory-PA/blob/main/qtsupervisory.png)]
*Interfaces principais do sistema supervisório.*

---

## 📋 Tabela de Conteúdos

* [Sobre o Projeto](#-sobre-o-projeto)
* [Principais Funcionalidades](#-principais-funcionalidades)
* [Tecnologias Utilizadas](#-tecnologias-utilizadas)
* [Como Executar](#-como-executar)
* [Estrutura do Projeto](#-estrutura-do-projeto)
* [Licença](#-licença)

---

## 💡 Sobre o Projeto

O `qtsupervisory-PA` foi desenvolvido como um projeto prático para a disciplina de Programação Avançada, utilizando a linguagem **C++** e o framework **Qt Creator**. O objetivo principal é demonstrar a criação de um sistema de supervisão fundamental, capaz de conectar um servidor, um produtor de dados e um consumidor de dados. Essa arquitetura permite a implementação de lógicas de monitoramento e controle.

A interface gráfica foi construída diretamente no **Qt Creator**, aproveitando as ferramentas de design e os recursos do framework Qt para criar uma aplicação robusta e interativa.

---

## ✨ Principais Funcionalidades

* 🔄 **Conexão Servidor-Cliente:** Estabelecimento de comunicação entre um servidor e um cliente.
* 📤 **Produção de Dados:** Mecanismo para gerar dados a serem monitorados.
* 📥 **Consumo de Dados:** Interface para receber e exibir os dados produzidos.
* 📊 **Visualização de Dados:** Exibição gráfica para o acompanhamento dos dados.
* ⚙️ **Interface Gráfica:** Janelas intuitivas para interação com o sistema.

---

## 🛠️ Tecnologias Utilizadas

O projeto foi desenvolvido utilizando as seguintes tecnologias:

* **C++**: Linguagem de programação principal.
* **Qt Creator**: Ambiente de desenvolvimento integrado (IDE) para a criação da interface gráfica e implementação da lógica.
* **Framework Qt**: Biblioteca de classes C++ que fornece ferramentas para o desenvolvimento de GUIs e aplicações multiplataforma.

---

## 🚀 Como Executar

Para executar este projeto localmente, você precisará ter o ambiente de desenvolvimento Qt Creator configurado.

### Pré-requisitos

* Ter o [Qt Creator](https://www.qt.io/download-open-source/) instalado.
* Ter um compilador C++ configurado (por exemplo, GCC).
* Ter o [Git](https://git-scm.com/downloads) instalado para clonar o repositório.

### Passos para Execução

1.  **Clone o repositório:**
    ```sh
    git clone [https://github.com/luiz-pytech/qtsupervisory-PA.git](https://github.com/luiz-pytech/qtsupervisory-PA.git)
    ```
2.  **Abra o projeto no Qt Creator:**
    Abra o arquivo `.pro` (arquivo de projeto do Qt) localizado na pasta do repositório utilizando o Qt Creator.
3.  **Configure o build:**
    O Qt Creator irá configurar o ambiente de build com base no arquivo `.pro`. Certifique-se de que o alvo de build correto esteja selecionado.
4.  **Construa o projeto:**
    Clique no botão "Build" (Construir) no Qt Creator.
5.  **Execute a aplicação:**
    Após a construção bem-sucedida, clique no botão "Run" (Executar) para iniciar o sistema supervisório.

---

## 📂 Estrutura do Projeto

A estrutura do projeto, sendo desenvolvido em Qt Creator, é tipicamente organizada da seguinte forma:

* `qtsupervisory-PA.pro`: Arquivo de projeto do Qt.
* Arquivos `.h` (headers): Declarações de classes.
* Arquivos `.cpp` (sources): Implementações das classes.
* Arquivos `.ui`: Arquivos de design da interface gráfica criados com o Qt Designer (integrado ao Qt Creator).
* Outros arquivos de recursos, se houver.

---

_Desenvolvido por Luiz-PyTech_ para disciplina ministrada pelo professor [Agostinho](https://github.com/agostinhobritojr/agostinhobritojr.github.io)
