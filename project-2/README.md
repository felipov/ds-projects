# Order Book (Sistema de Ordens de Compra e Venda)

## Descrição
Sistema para gerenciamento de ordens de compra e venda de uma ação. O sistema armazena ordens
em aberto e executa automaticamente transações quando há compatibilidade entre ordens.

Funcionalidades:
- Submeter uma nova ordem;
- Cancelar uma ordem já existente;
- Exibir as ordens e transações registradas;
- Obter uma cópia dos dados registrados.

## Compilação e Execução
No Windows:

`g++ main.cpp OrderBook.cpp Order.cpp Transaction.cpp -o order_book.exe`

`.\order_book.exe`

No Linux / macOS:

`g++ main.cpp OrderBook.cpp Order.cpp Transaction.cpp -o order_book`

`./order_book`

## Organização dos Dados
O sistema conta com três classes principais: `Order`, `OrderBook` e `Transaction`; e 
cinco classes auxiliares: `NodeOrder`, `NodeTransaction`, `BuyList`, `SellList` e
`TransactionList`.

### Descrição
**Classes Principais:**

`Order`: Armazena os dados relativos a uma ordem de compra ou venda.

`Transaction`: Armazena os dados relativos a uma transação.

`OrderBook`: É o controlador do sistema, é a classe responsável por armazenar 
novas ordens, executar automaticamente ordens compatíveis, exibir o estado
atual do sistema e permitir a cópia dos dados existentes para um novo array dinâmico.

`NodeOrder`: Nó usado nas listas de ordens, guarda uma ordem e um ponteiro
para o próximo elemento.

`NodeTransaction`: Nó usado nas listas de transações, guarda uma transação
e um ponteiro para o próximo elemento.

`BuyList`: Lista encadeada que armazena no sistema todas as ordens de compra
existentes.

`SellList`: Lista encadeada que armazena no sistema todas as ordens de venda
existentes.

`TransactionList`: Lista encadeada que armazena no sistema todas as transações
executadas.


