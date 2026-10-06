\# RootFinder SDK (Студент А)



Бібліотека для знаходження коренів нелінійних рівнянь на C.



\## Функції (C-interface):

\- `rf\_bisection`: Метод дихотомії (бісекції).

\- `rf\_newton`: Метод Ньютона (дотичних).

\- `rf\_secant`: Метод січних.

\- `rf\_residual`: Обчислення нев'язки |f(x)|.



\## Коди помилок (enum):

\- 0: RF\_OK (Успіх)

\- 1: RF\_ERR\_NULL\_ARG (Нульовий вказівник)

\- 2: RF\_ERR\_INVALID\_INTERVAL (Некоректний інтервал)

\- 3: RF\_ERR\_NO\_SIGN\_CHANGE (Немає зміни знаку на кінцях)

\- 4: RF\_ERR\_NO\_CONVERGENCE (Немає збіжності за maxIter)

\- 5: RF\_ERR\_BAD\_PARAM (Некоректний параметр eps або maxIter)

\- 6: RF\_ERR\_NOT\_FINITE (Результат не є скінченним числом)

\- 7: RF\_ERR\_ZERO\_DIVISION (Ділення на нуль)

