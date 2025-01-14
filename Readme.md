#   Proiect: Turnurile din Hanoi

## Detalii despre Implementare
Acest proiect implementeaza jocul "Turnurile din Hanoi" folosind limbajul de programare C++

### Structura Proiectului 
- **main.cpp**: Codul sursa principal care implementeaza logica jocului.
- **Dockerfile**: Configurarea necesara pentur a construi imaginea Docker a apicatiei.
- **.gitlab-ci.yml**: Configuratia pipeline-ului CI/CD pentru GitLab.
- **/gitignore**: Listeaza fisierele si directoarele care trebuie ignorate de Git.

## Platforma Software Utilizata
- **Limbaj**: C++
- **Compilator**: GCC (GNU Compiler Collection)
- **Platforma CI/CD**:  GitLab
- **Docker**: Utilizat pentru containerizare si livrarea aplicatiei

### Configuratii Software Necesare
1. **Docker**
    -   Asigura-te ca Docker este instalat pe masina ta locala.
    -Comanda pentru instalare:
     ```bash
     sudo apt install docker.io
     ```
2. **GitLab CI/CD**
    - Pipeline-ul automat pentru build, push si deploy este configurat in `.gitlab-ci.yml`.
3. **G++**
    - Necesita G++ pentru compilarea manuala a codului daca nu folosesti Docker:
    ```bash
    sudo apt install g++
    ```
## Rezultate
Programul afiseaza pasii necesari pentru rezolvarea problemei Turnurilor Din Hanoi pentru orice numar de discuri introdus de utilizator.

Exemplu de iesire pentru 3 discuri:
```
Introduceti nuarul de discuri: 3
Muta discul 1 de pe A pe C
Muta discul 2 de pe A pe B
Muta discul 1 de pe C pe B
Muta discul 3 de pe A pe C
Muta discul 1 de pe B pe A
Muta discul 2 de pe B pe C
Muta discul 1 de pe A pe C
```

## Modalitate de Rulare 

### Rulare Locala (Fara Docker)
1. Compileaza codul folosing G++:
    ```bash
    g++ -o turnuri_hanoi main.cpp
    ```
2. Ruleaza aplicatia:
    ```bash 
    ./turnuri_hanoi
    ```
### Rulare folosind Docker 
1. Construieste imaginea Docker:
    ```bash
    docker build -t turnuri_hanoi:latest .
    ```
2. Ruleaza containerul:
    ```bash
    docker run -it --rm turnuri_hanoi
    ```
### Rulare Automata prin GitLab CI/CD
1. Fa un comit al codului in branch-ul principal (`main`)
2. Pipeline-ul GitLab va face automat urmatoarele:
    - Construieste imaginea Docker.
    - Impinge imaginea in **GitLab Container Registry**.
    - Ruleaza containerul pe serverul specificat (daca este configrat).

## Captura de Ecran
![Captura de ecran a aplicatiei]()

Aceasta este o captura de ecran demonstrativa ce contine secventa de testare.