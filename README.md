# Homework-2-3
<p>Программа на вход принимает файл(table.txt), который содержит таблицу инциндентности.
Из исходных данных программа создаёт код для графа на языке DOT и помещает это в файл(tablewr.txt) и указывает связанный ли граф</p>
<p>Пример файла table.txt</p>
<p> &ensp;abcehjtgf<br>
1101000000<br>
2110000000<br>
3001100000<br>
4000110000<br>
5000001111<br>
6000000100<br>
7000000010<br>
8000000001</p>
<p>На выход в файл tablewr.txt он запишет</p>
<p>graph H{<br>
5--8<br>
5--7<br>
5--6<br>
5--5<br>
4--4<br>
3--4<br>
1--3<br>
2--2<br>
1--2<br>
}</p>
<p>Построение графа производим на сайте https://dreampuf.github.io/GraphvizOnline</p>
