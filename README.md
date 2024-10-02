# Checker Tema 1 - 2021
Checker-ul este o aplicație de testare automată a temelor. Este un produs open-source realizat de către și pentru studenții din Facultatea de Automatică și Calculatoare - UPB, și este menit atât să usureze munca asistenților de a corecta teme cât și sa ofere studenților o evaluare cât mai obiectivă.

## Rularea checker-ului
Pentru a verifica functionarea checker-ului va trebui sa descarcati tot depozitul de mai sus, dupa aceasta deschideti un terminal in folderul in care se afla depozitul descarcat si scrieti urmatoarea comanda:
```shell
./checker.sh
````

## Descrierea solutiei
0. Din fisierul c.in am retinut in 5 variabile opX , X={1,2,3,4,5} optiunile programului
1. Citirea si inserarea datelor din fisiere in lista utilizand functia addData()
   a) Am stocat elementele alocate dinamic (numele echipei, tipul Player cu campurile sale) in structura Evidence pentru a usura si eficientiza eliberarea memoriei direct din aceasta structura la finalul problemei
   b) Functia initList() are rolul de a initializa o Lista (dublu inlantuita cu santinela)
   c) Am utilizat 3 siruri cu rol de buffer pentru a putea aloca dinamic si cu exactitate campurile numelor echipei si al jucatorilor
   d) Am utilizat functia deleteTrailing() in cazul numelor echipei si a jucatorilor pentru a elminina spatiile tip whitespace astfel incat rezultatul sa fie identic cu cel de referinta (cu scopul functionarii checker-ului)
   e) Am calculat punctajul echipelor cu ajutorul functiei calculPunctajEchipa() si dupa am adaugat in lista echipele prin functia addToHead()
2. Cu ajutorul functiei delTillPow2() am eliminat din lista echipele cu punctaj minim pana am obtinut un numar de echipe de tip putere a numarului 2 (log2(nrEchipe)==(int)log2(nrEchipe))
3. Crearea a doua stive (de castigatori si pierzatori) si dupa inserarea elementelor din stiva de castigatori in lista pentru a putea simula meciurile
   a) Functia matchMaking() realizeaza urmatoarele operatii:
        i) initiaza doua stive W, Lo (Winners and Losers) si compara cate doua echipe ca punctaj pentru a determina cine castiga si cine pierde pentru a le insera corespunzator in cele doua stive, operatiunea repetandu-se pana cand in lista de echipe nu mai exista nicio echipa
        ii) Stiva cu pierzatori se goleste si reintroducem in lista echipele din stiva W pentru a relua meciurile dintre echipele castigatoare pana la meciul final dintre ultimele doua echipe cu cel mai mare punctaj
        iii) Cand in lista ajungem sa avem 8 echipe, le vom retine si le vom utiliza ulterior intr-un arbore de tip BST (Binary Search Tree), pentru cerinta 4. utilizand functia addToBST()
4. In urma realizarii meciurilor, in arborele binar de cautare se vor afla echipele de primele 8 locuri ca efect al functiei matchMaking() utilizata la cerinta 3.
   a) Echipele se vor afla in arborele BST dupa regula de baza al acestei structuri de date:
        i) In stanga radacinii se vor afla echipele cu cel mai mic punctaj iar in dreapta radacinii se vor afla echipele cu cel mai mare punctaj
        ii) Functia rightInOrder() recursiva are rolul de a parcurge arborele binar de cautare dupa regula DRS (inordine de la dreapta la stanga) pentru a avea o afisare in ordine descrescatoare a punctajului Echipelor, cu scopul realizarii clasamentului corespunzator
        iii) De mentionat este si faptul ca daca doua echipe vor avea acelasi punctaj, clasamentul se va realiza descrescator in functie de nume
5. Pentru a realiza arborele AVL cu echipele salvate in arborele BST am utilizat functia de transfer fromBSTToAVL() recursiva pentru a parcurge in mod DRS (inordine de la dreapta la stanga) arborele BST si introducerea echipelor in mod corespunzator in arborele AVL
   a) Functia addToAVL() foloseste functiile de rotatie leftRot(), rightRot() ,LRRot() si RLRot() pentu a pastra arborele echilibrat
   b) Se afiseaza prin intermediul functiei rightInOrderAVL() iterativa care se foloseste de coada AVQueue() pentru a parcurge elementele arborelui pe nivele, respectand astfel afisarea data de cerinta
   c) in final se sterge coada utilizata prin intermediul functiei deleteAVQueue()

Finalul programului: In cazul in care au fost folosite, structurile de date sunt sterse prin intermediul functiilor asociate (Ex: deleteAVL(), deleteBST(), deleteQueue(), delList(),...) si elementele de tip Player si numele asociat echipelor declarate dinamic sunt dealocate prin intermediul structurii Evidence si a functiei deleteEvidence() care "va da free()" la toate elementele introduse initial si folosite pe parcursul programului pentru a nu avea scurgeri de memorie (Memory leaks) si inchidem fisierele deschise (f.in, c.in, f.out).