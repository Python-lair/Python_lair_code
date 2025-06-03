import turtle as tr
# импортирунм модуль turtle

t = tr.Turtle() # создаем черепашку
t.speed(0) #задаем скорость

colors = ("red", "green", "blue")
# картеж с цветами
turtles = ("turtle", "circle", "square")
# картеж с формами черепашки

for j in range(17):
	for i in range (3):
		t.color(colors[i]) 
		# меняем цвет черепашки
		t.shape(turtles[i])
		# меняем форму черепашки
		t.forward(500)
		# сдвигаем черепашку на 500
		t.right(170)
		# поворачиваем черепашку на 170°

t.penup() 
# поднимаем перо
while True:
	t.goto(-200, 200)
# зацикливаем черепашку что бы
# не пропало окно

