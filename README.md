# DemoCPPGame
## Игровой проект-прототип.
### Описание
* Проект написан с помощью C++ и Blueprint в движке Unreal Engine 4.24.1
* Были реализованы простые основные механики Unreal Engine 4: бег, поворот, прыжок, движение акторов, триггеры.
* Цель проекта - демонстрация навыков.

### Игровая механика | С++ Classes
 
1. *Действия*
  * Бег
  
<a href="https://radikalno.ru" target="_blank"><img src="https://cdn1.radikalno.ru/uploads/2020/2/16/5c79c46c5cd9a637c87cecc86556e34a-full.png" border="0"/></a>
---

  * Так же были использованы built-in повороты, прыжок и камера. 

2. *Сущности*
  * FlyingCloud
 
<a href="https://radikalno.ru" target="_blank"><img src="https://cdn1.radikalno.ru/uploads/2020/2/16/360baddce81fd7bea9d9c9a0be9dceb2-full.png" border="0"/></a>

---

 * RotatingActor 
 
 <a href="https://radikalno.ru" target="_blank"><img src="https://cdn1.radikalno.ru/uploads/2020/2/16/318b34e31214a83f813cb4b2119eabdb-full.png" border="0"/></a>

---

 * MyBaseCharacter
 
 <a href="https://radikalno.ru" target="_blank"><img src="https://cdn1.radikalno.ru/uploads/2020/2/16/563d6d639b629996262a4235e873152f-full.png" border="0"/></a>
 
 3. *Прочее*
 
 * MyTriggerBox
 
 <a href="https://radikalno.ru" target="_blank"><img src="https://cdn1.radikalno.ru/uploads/2020/2/16/6a89ea3a20adcedbda1ad85cf1f4d0c0-full.png" border="0"/></a>
 
 ---
 
 * Также были созданы и использованы С++ классы, формирующие правила игры, точку старта уровня.
 
### Демонстрация
* Прохождение проекта в редакторе, доступ по ссылке.

  **https://www.youtube.com/watch?v=NR8mOqcHu3E**

---

* Сообщения в левом верхнем углу экрана показывают о выполнении условий игры (использование определенных классов, условие пройгрыша - падение, условие выйгрыша - попадание в триггер).
