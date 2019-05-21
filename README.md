# Fillit

## О проекте

**Дано**: набор тетрамино  
**Задача**: найти наименьший размер квадрата, куда можно положить эти тетрамино.  
Положить их в порядке максимально близком к изначальному  
[Полное условие](https://github.com/liftchampion/fillit/blob/master/fillit.en.pdf)  

**Решение**:
+ Методом *танцующих ссылок Кнута* находится минимальный размер квадрата.  
+ Наивным брутфорсом находится раскладка, удовлетворяющая требованиям о порядке.  

**Итог**:
Танцующие ссылки Кнута - прекрасный алгоритм, но он плохо подходит для этой задачи,  
из-за того, что в условии требуют найти определенный порядок, а танцующие ссылки находят какой-либо.  
Написать же такое дополнительное условие, чтобы танцующие ссылки искали нужное решение - задача нетривиальная.  
В итоге пришлось заново решать ту же задачу и брутфорсом подбирать нужный порядок.  
Несмотря на это, у моего решения достаточно неплохая скорость (быстрее многих, которые я видел).  
Но алгоритмы брутфорса, работающие на битовых полях и хранящие карту в одном 128-битном инте, работают быстрее.  

### Тетрамино
![tetras](https://raw.githubusercontent.com/liftchampion/fillit/master/imgs/tetras.png)
### Ответ
![answer](https://raw.githubusercontent.com/liftchampion/fillit/master/imgs/total.png)
### Ввод 
![input](https://raw.githubusercontent.com/liftchampion/fillit/master/imgs/input.png)
### Вывод
![output](https://raw.githubusercontent.com/liftchampion/fillit/master/imgs/output.png)

**Thanks to [Beth Nenniger](https://medium.com/@bethnenniger) for images from her [article](https://medium.com/@bethnenniger/fillit-solving-for-the-smallest-square-of-tetrominos-c6316004f909)**

*C код написан в [Norminette code style](https://github.com/liftchampion/Norminette)*
