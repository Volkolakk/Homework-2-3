# Homework-2-3
<p>Программа на вход принимает фаил(table.txt), который содержит таблицу инцендентности.
Из исходных данных программа создаёт код для графа на языке DOT и помещает это в фаил(tablewr.txt) и указывает связанный ли график</p>
<p>Пример файла table.txt</p>
<p> abcehjtgf<br>
1101000000<br>
2110000000<br>
3001100000<br>
4000110000<br>
5000001111<br>
6000000100<br>
7000000010<br>
8000000001</p>
<p>на выход в файл tablewr.txt он запишет</p>
<p>graph H<br>{
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
