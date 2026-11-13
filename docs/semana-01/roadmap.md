# Semana 01 — C++ STL, I/O rápido, tipos e complexidade

**Status:** em andamento. Diagnóstico dispensado (conhecimento inicial baixo em STL): os Dias 2 a 5 são explicados do zero, com exemplos.
**Horas por dia:** ~4 h
**Estrutura:** Dias 1 a 5 = estudo com o tutor. Dias 6 e 7 = livres para o desafio da semana (sem IA).

## Assunto
- C++ com STL: `vector`, `pair`, `set`, `map`, `priority_queue`, `sort`, `lower_bound`
- Leitura/escrita rápida, tipos (`int` vs `long long`, overflow)
- Análise de complexidade (cerca de 10^8 operações simples por segundo)

## Competências-alvo (marcar ao fim da semana)
- [ ] Estimo, antes de codar, se uma solução passa no limite de tempo
- [ ] Sei quando `int` estoura e uso `long long` (e `__int128` quando preciso) sem pensar duas vezes
- [ ] Escrevo I/O rápido de cabeça e sei o que quebra ao misturar `cin`/`scanf`
- [ ] Escrevo comparadores corretos (ordem fraca estrita) para `sort`, `set`, `map` e `priority_queue`
- [ ] Uso `lower_bound`/`upper_bound` em `vector` e como método de `set`/`map`
- [ ] Sei apagar e inserir em `set`/`map` sem invalidar iteradores
- [ ] Conheço as armadilhas de `operator[]` em `map`, `multiset::erase(valor)` vs `erase(iterador)` e `priority_queue` sem remoção
- [ ] Domino `pair`/`tuple`, ordenação por vários critérios e compressão de coordenadas

## Dia 1 — I/O rápido, tipos e estimativa de complexidade (concluído)
- **Explicação:** `ios::sync_with_stdio(false); cin.tie(nullptr);`, `'\n'` vs `endl`, limites de `int` (~2,1·10^9) e `long long` (~9,2·10^18), overflow em somas e produtos, tabela "n → complexidade aceitável" para 10^8 op/s.
- **Armadilhas:** `a * b` em `int` antes de atribuir a `long long`; literais (`1LL << 40`); somar 2·10^5 valores de até 10^12; `%` com negativos.
- **Exercícios:**
  1. Weird Algorithm — CSES
  2. Missing Number — CSES
  3. Increasing Array — CSES
  4. Maximum Subarray Sum — CSES
  5. Theatre Square (problema 1A) — Codeforces (opcional, treina overflow e divisão com arredondamento para cima)
- **Revisão:** 2-3 perguntas no fim do dia.

## Dia 2 — `vector`, `pair`, `sort`, busca binária
- **Explicação:** `vector` (push_back amortizado O(1), reserve), `pair`/`tuple`, `sort` O(n log n) com comparador, `lower_bound`/`upper_bound` em vetor ordenado O(log n), `unique`, compressão de coordenadas, dois ponteiros após ordenar, busca binária na resposta.
- **Armadilhas:** comparador com `<=`; `sort` em `vector<pair>` e critério de desempate; `lower_bound` em `set` com a função livre (vira O(n)); `v.size() - 1` com `size_t` e vetor vazio; `lo + hi` estourando e overflow dentro da função de checagem da busca binária.
- **Exercícios (dificuldade crescente, ~4 h):**
  - Fáceis (sintaxe e lógica):
    1. Distinct Numbers — CSES
    2. Next Round (158A) — Codeforces
    3. Apartments — CSES
    4. Ferris Wheel — CSES
  - Médios (contextualizados):
    5. Sum of Two Values — CSES (`pair` valor/índice)
    6. Stick Lengths — CSES
    7. Books (279B) — Codeforces (prefixos + `upper_bound`)
    8. Factory Machines — CSES (busca binária na resposta)
  - Difícil (junta os tópicos do dia):
    9. Sum of Four Values — CSES (tentar com `lower_bound`)
  - Extras: Array Division, Tasks and Deadlines, Movie Festival — CSES; Maximum Median (1201C) — Codeforces
- **Revisão:** 2-3 perguntas no fim do dia.

## Dia 3 — `set`, `multiset`, `map`
- **Explicação:** árvore balanceada, O(log n) por operação, iteradores, `lower_bound`/`upper_bound` como método, `begin()`/`prev(end())`, `erase` por valor vs por iterador, `map` com `operator[]` vs `find`/`count`.
- **Armadilhas:** `m[x]` cria a chave; `multiset::erase(x)` apaga todos os iguais; iterar e apagar ao mesmo tempo; `set` de `pair` com desempate.
- **Exercícios:**
  1. Concert Tickets — CSES
  2. Traffic Lights — CSES
  3. Towers — CSES
  4. Playlist — CSES
  5. (a definir pelo tutor) — Codeforces
- **Revisão:** 2-3 perguntas.

## Dia 4 — `priority_queue` e comparadores personalizados
- **Explicação:** max-heap por padrão, min-heap com `greater<>`, heap de `pair`/`tuple`, comparador próprio com `struct`, push/pop O(log n), top O(1), remoção "preguiçosa" (lazy deletion) quando o elemento não está mais válido.
- **Armadilhas:** esquecer o `greater<>`; `top()` em fila vazia; comparador que não é ordem fraca estrita; custo de copiar structs grandes.
- **Exercícios:**
  1. Room Allocation — CSES
  2. Movie Festival II — CSES
  3. Restaurant Customers — CSES
  4. Sliding Window Median — CSES
  5. (a definir pelo tutor) — Codeforces
- **Revisão:** 2-3 perguntas.

## Dia 5 — Integração e complexidade
- **Explicação:** combinar as estruturas, checklist antes de submeter (limites, overflow, I/O, casos de borda), como estimar tempo e memória, como testar com entrada máxima.
- **Exercícios:**
  1. Sliding Window Cost — CSES
  2. Nested Ranges Check — CSES
  3. Collecting Numbers II — CSES
  4. 1-2 problemas de ~1800-2000 no Codeforces (escolhidos pelo tutor após o diagnóstico; só com certeza de que existem)
- **Revisão geral da semana:** 2-3 perguntas + conferência do checklist de competências.

## Dias 6 e 7 — Livres
Atacar o desafio da semana sozinho, sem ajuda de IA. Se ninguém resolver, corrigimos juntos na reunião seguinte, em outra conversa.

## Anotações pessoais
- Lacunas encontradas no diagnóstico:
- Erros recorrentes:
- Código-base que quero guardar (template de I/O, comparadores, etc.):
