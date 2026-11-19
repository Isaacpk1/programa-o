# Semana 02 — Técnicas básicas + fechamento da STL

**Status:** planejada.
**Horas por dia:** ~4 h
**Estrutura:** Dias 1 a 5 = estudo com o tutor. Dias 6 e 7 = livres para o desafio da semana (sem IA).

> **Por que é um "mix":** a Semana 01 parou no fim do Dia 2. Os Dias 3, 4 e 5 dela (`set`/`multiset`/`map`, `priority_queue` e integração) **não foram descartados**: foram encaixados aqui, cada um junto da técnica nova que mais usa aquela estrutura. Simulação quase sempre precisa de `set`/`map`/`priority_queue`, e força bruta e backtracking exigem saber estimar complexidade. Então um assunto treina o outro.

## Assunto

**Novo (Semana 02):**
- Simulação e implementação cuidadosa
- Força bruta e enumeração de casos
- Backtracking (gerar subconjuntos e permutações)
- Recursão

**Herdado da Semana 01 (Dias 3-5):**
- `set`, `multiset`, `map` (iteradores, `lower_bound` como método, `erase`)
- `priority_queue` e comparadores personalizados
- Integração das estruturas + checklist antes de submeter

## Como os assuntos foram combinados

| Dia | Técnica nova | Estrutura herdada da Semana 01 | Por que juntos |
|-----|--------------|--------------------------------|----------------|
| 1 | Recursão + força bruta / enumeração | complexidade (revisão) | força bruta só funciona se você souber estimar 2^n, n! e n² antes de codar |
| 2 | Simulação cuidadosa | `set` / `multiset` / `map` | a simulação "ingênua" é O(n²); com árvore balanceada vira O(n log n) |
| 3 | Simulação por eventos | `priority_queue` | "qual é o próximo evento?" é exatamente o `top()` de um heap |
| 4 | Backtracking (subconjuntos e permutações) | `next_permutation`, bitmask, `vector` | gerar todas as opções e cortar cedo (poda) |
| 5 | Integração | tudo junto | problemas que misturam simulação + estrutura + casos de borda |

## Competências-alvo (marcar ao fim da semana)

**Técnicas novas**
- [ ] Escrevo uma função recursiva com caso base correto e sei estimar a profundidade da pilha
- [ ] Antes de codar uma força bruta, calculo o número de casos (2^n, n!, C(n,k), n²) e sei se passa
- [ ] Enumero subconjuntos com bitmask (`for mask in [0, 2^n)`) e com recursão "pega / não pega"
- [ ] Gero permutações com `next_permutation` (vetor ordenado antes!) e com backtracking + `usado[]`
- [ ] Sei aplicar poda: parar um ramo quando ele já não pode dar resposta melhor/válida
- [ ] Implemento simulações longas seguindo o enunciado regra a regra, sem "atalhos" que mudam o comportamento
- [ ] Testo a simulação contra uma força bruta em entradas pequenas (stress test)

**Herdadas da Semana 01**
- [ ] Uso `lower_bound`/`upper_bound` como **método** de `set`/`map` (não a função livre)
- [ ] Sei apagar e inserir em `set`/`map` sem invalidar iteradores
- [ ] Conheço as armadilhas de `operator[]` em `map`, `multiset::erase(valor)` vs `erase(iterador)` e `priority_queue` sem remoção
- [ ] Escrevo comparadores corretos (ordem fraca estrita) para `set` e `priority_queue`
- [ ] Uso remoção preguiçosa (lazy deletion) em `priority_queue`

---

## Dia 1 — Recursão e força bruta (enumeração de casos)

**Explicação curta**
- **Recursão:** toda função recursiva tem (1) caso base e (2) chamada que *diminui* o problema. Custo = (nº de chamadas) × (trabalho por chamada). Fibonacci ingênuo é O(φ^n) porque recalcula; Torre de Hanói faz 2^n − 1 movimentos.
- **Pilha:** cada chamada ocupa memória. Profundidade de ~10^5 a 10^6 costuma passar em C++ (no Codeforces, sim; em outros juízes, pode estourar). Recursão com profundidade 10^7 → reescreva iterativo.
- **Força bruta:** testar todas as possibilidades. Antes, conte quantas são e multiplique pelo custo de testar cada uma. Tabela útil (com ~10^8 op/s):

| Busca | n máximo típico |
|-------|-----------------|
| n! (permutações) | n ≤ 10-11 |
| 2^n (subconjuntos) | n ≤ 20-25 |
| 2^n · n | n ≤ 20 |
| n³ | n ≤ 500 |
| n² | n ≤ 5000-10^4 |

- **Enumeração de casos:** às vezes não se testa "tudo", e sim as *poucas formas* que a resposta pode ter (ex.: fixar um elemento e procurar o outro com `map`). Isso transforma O(n²) em O(n log n).

**Código-base: subconjuntos com bitmask**
```cpp
int n; vector<long long> a(n);
for (int mask = 0; mask < (1 << n); mask++) {
    long long soma = 0;
    for (int i = 0; i < n; i++)
        if (mask >> i & 1) soma += a[i];
    // usar soma
}
// custo: O(2^n · n)
```

**Armadilhas**
- Esquecer o caso base → recursão infinita → *stack overflow* (RE).
- `1 << n` com `n ≥ 31` estoura `int`; use `1LL << n`.
- Somas de subconjuntos com valores até 10^9 estouram `int` (revisão da Semana 01).
- Passar `vector` por valor na recursão: cópia a cada chamada. Use `const vector<int>&`.

**Exercícios (dificuldade crescente)**
1. Tower of Hanoi — CSES (fácil: recursão pura)
2. Gray Code — CSES (fácil/médio: recursão construtiva)
3. Apple Division — CSES (médio: enumerar 2^n divisões)
4. Preparing Olympiad (550B) — Codeforces (médio: bitmask com várias restrições)
5. Sum of Four Values — CSES (difícil: enumerar pares + `map`, cuidado com índices repetidos)

**Revisão do dia:** 2-3 perguntas.

---

## Dia 2 — Simulação cuidadosa + `set` / `multiset` / `map` (herdado do Dia 3 da Semana 01)

**Explicação curta**
- **Simulação:** fazer exatamente o que o enunciado descreve, passo a passo. A dificuldade não é a ideia, é **não errar**. Método:
  1. Leia o enunciado duas vezes e liste as regras numeradas (inclusive as de desempate).
  2. Escolha a estrutura que representa o *estado* (o que muda a cada passo).
  3. Escreva uma função por regra; nomes claros, sem "truques" no meio.
  4. Teste à mão o exemplo do enunciado, depois os casos de borda (n = 1, todos iguais, tudo vazio).
- **Quando a simulação ingênua é lenta:** se cada passo procura "o menor ≥ x" ou remove do meio, um `vector` gasta O(n) por passo → O(n²). Um `set`/`multiset` faz isso em O(log n).
- **`set` / `multiset` / `map`:** árvore balanceada, O(log n) para `insert`, `erase`, `find`, `lower_bound`. `begin()` é o menor, `prev(end())` é o maior. `map<K,V>` é um `set` de chaves com valor associado.

| Operação | Custo |
|----------|-------|
| `s.insert(x)`, `s.erase(it)`, `s.find(x)` | O(log n) |
| `s.lower_bound(x)` (método) | O(log n) |
| `lower_bound(s.begin(), s.end(), x)` (função livre) | **O(n)** em `set`! |
| `s.size()`, `s.begin()` | O(1) |

**Armadilhas**
- `m[x]` **cria** a chave com valor 0 se não existir; para só consultar, use `m.count(x)` ou `m.find(x)`.
- `ms.erase(x)` apaga **todas** as cópias de `x` no `multiset`; para apagar uma, use `ms.erase(ms.find(x))` (e confira se `find` não é `end()`).
- Apagar enquanto itera: `it = s.erase(it);` em vez de `s.erase(it); it++;`.
- `prev(s.begin())` ou `*s.end()` → comportamento indefinido. Sempre checar se o iterador é válido.
- Simulação: esquecer uma regra de desempate do enunciado é o erro nº 1.

**Exercícios (dificuldade crescente)**
1. Queue at the School (266B) — Codeforces (fácil: simulação direta)
2. Concert Tickets — CSES (médio: `multiset` + `upper_bound` + apagar um só)
3. Josephus Problem I — CSES (médio: simulação com fila)
4. Traffic Lights — CSES (médio/difícil: `set` de posições + `multiset` de tamanhos)
5. Josephus Problem II — CSES (difícil: simulação que precisa de estrutura com "k-ésimo elemento"; pesquise *ordered set / policy-based data structures*)
- Extras: Towers — CSES; Playlist — CSES

**Revisão do dia:** 2-3 perguntas.

---

## Dia 3 — Simulação por eventos + `priority_queue` (herdado do Dia 4 da Semana 01)

**Explicação curta**
- **Simulação por eventos:** em vez de simular tempo 1, 2, 3, …, 10^9, pule direto para o *próximo evento* (chegada, saída, fim de tarefa). Ordene os eventos ou mantenha-os num heap.
- **`priority_queue`:** max-heap por padrão. `push`/`pop` O(log n), `top` O(1). Min-heap: `priority_queue<T, vector<T>, greater<T>>`. Com `pair`, compara pelo `first` e desempata pelo `second`.
- **Comparador próprio:**
```cpp
struct Cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first != b.first) return a.first > b.first; // menor first sai primeiro
        return a.second > b.second;                      // desempate
    }
};
priority_queue<pair<int,int>, vector<pair<int,int>>, Cmp> pq;
```
  Atenção: o comparador do heap é "invertido" — `return a > b` gera um **min**-heap.
- **Remoção preguiçosa (lazy deletion):** `priority_queue` não remove do meio. Marque o item como inválido e, ao fazer `top()`, descarte enquanto o topo estiver inválido.
- **Eventos no mesmo instante:** decida (pelo enunciado!) se "sair" vem antes de "entrar". Codifique isso no desempate da ordenação.

**Armadilhas**
- Esquecer o `greater<>` e pegar o maior em vez do menor.
- `top()`/`pop()` em heap vazio → RE.
- Comparador com `>=` ou `<=` (não é ordem fraca estrita) → comportamento indefinido.
- Eventos com mesmo tempo processados na ordem errada.

**Exercícios (dificuldade crescente)**
1. Restaurant Customers — CSES (fácil: eventos ordenados, entrada/saída)
2. Room Allocation — CSES (médio: min-heap de "quarto livre a partir de")
3. Movie Festival II — CSES (médio/difícil: `multiset` de membros + ordenação por fim)
4. Potions (Hard Version) (1526C2) — Codeforces (difícil: simulação gulosa + min-heap para "desfazer" a pior escolha)
5. Sliding Window Median — CSES (difícil: dois `multiset` balanceados ou heaps com lazy deletion)

**Revisão do dia:** 2-3 perguntas.

---

## Dia 4 — Backtracking: subconjuntos e permutações

**Explicação curta**
- **Backtracking** = recursão que constrói a resposta peça por peça: escolhe → recursa → **desfaz** a escolha. É uma força bruta organizada que permite **podar** (abandonar um ramo cedo).
- **Subconjuntos (pega / não pega):** O(2^n).
```cpp
vector<int> atual;
void sub(int i) {
    if (i == n) { /* processar atual */ return; }
    sub(i + 1);                  // não pega a[i]
    atual.push_back(a[i]);
    sub(i + 1);                  // pega a[i]
    atual.pop_back();            // desfaz
}
```
- **Permutações com `usado[]`:** O(n! · n).
```cpp
vector<int> perm; vector<bool> usado(n);
void gera() {
    if ((int)perm.size() == n) { /* processar perm */ return; }
    for (int i = 0; i < n; i++) if (!usado[i]) {
        usado[i] = true; perm.push_back(a[i]);
        gera();
        perm.pop_back(); usado[i] = false;   // desfaz
    }
}
```
- **`next_permutation`:** gera a próxima permutação em ordem lexicográfica e lida sozinho com repetidos. Use `sort` antes e `do { ... } while (next_permutation(v.begin(), v.end()));`.
- **Poda:** cortar um ramo quando (a) ele já viola uma restrição, (b) já não pode superar a melhor resposta, ou (c) é simétrico a outro já explorado. Boa poda transforma "impossível" em "passa com folga".

**Armadilhas**
- Esquecer de desfazer a escolha (`pop_back`, `usado[i] = false`) → estado "sujo" nos próximos ramos.
- `next_permutation` sem ordenar antes → pula permutações.
- Gerar permutações repetidas quando há elementos iguais (use `next_permutation` ou pule iguais no mesmo nível).
- Checar a restrição só no fim (sem poda) quando ela poderia ser checada no meio.

**Exercícios (dificuldade crescente)**
1. Creating Strings — CSES (fácil: permutações sem repetição, `next_permutation`)
2. Shower Line (431B) — Codeforces (fácil/médio: testar as 5! ordens)
3. Lucky Numbers (96B) — Codeforces (médio: gerar números por recursão)
4. Chessboard and Queens — CSES (médio/difícil: backtracking com poda por coluna e diagonais)
5. Grid Paths — CSES (muito difícil: 4^48 caminhos sem poda; exige podas fortes para passar)

**Revisão do dia:** 2-3 perguntas.

---

## Dia 5 — Integração (herdado do Dia 5 da Semana 01)

**Explicação curta**
- Problemas reais misturam: simular regras + escolher a estrutura certa + cuidar de overflow e casos de borda.
- **Stress test** (ferramenta mais útil da semana): escreva uma força bruta lenta e certa, gere entradas pequenas aleatórias e compare com a solução rápida até achar diferença.
```bash
for i in $(seq 1 1000); do
  ./gen $i > in.txt
  ./rapida < in.txt > a.txt
  ./brute  < in.txt > b.txt
  cmp -s a.txt b.txt || { echo "diferença no teste $i"; break; }
done
```
- **Checklist antes de submeter:** limites → complexidade cabe? · `long long` onde precisa? · I/O rápido? · n = 1, tudo igual, valores máximos? · empates tratados como o enunciado manda?

**Exercícios (dificuldade crescente)**
1. Collecting Numbers II — CSES (médio: atualizar a resposta só nos vizinhos afetados)
2. Nested Ranges Check — CSES (médio/difícil: ordenação com desempate cuidadoso)
3. Sliding Window Cost — CSES (difícil: dois `multiset` + somas em `long long`)
4. Trash Problem (1418D) — Codeforces (~2100: simulação com consultas usando `set` de posições e `multiset` de distâncias)

**Revisão geral da semana:** 2-3 perguntas + conferência do checklist de competências.

---

## Dias 6 e 7 — Livres
Atacar o desafio da semana sozinho, sem ajuda de IA. Se ninguém resolver, corrigimos juntos na reunião seguinte, em outra conversa.

## Anotações pessoais
- Lacunas encontradas:
- Erros recorrentes:
- Código-base que quero guardar (bitmask, backtracking, stress test, comparadores):
