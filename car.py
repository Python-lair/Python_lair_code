import turtle as tr

t = tr.Turtle()

def koleso(r): 
    t.fillcolor("black")
    t.pendown()
    t.begin_fill()
    t.circle(r)
    t.end_fill()
    t.penup()
    t.right(-90)
    t.forward(r / 2)
    t.right(90)
    t.fillcolor("grey")
    t.pendown()
    t.begin_fill()
    t.circle(r / 2)
    t.end_fill()
    t.penup()
    t.right(90)
    t.forward(r / 2)
    t.right(-90)
# функция для рисования колеса


t.fillcolor("green") 
t.penup()
t.goto(-250, -25)
t.begin_fill()
t.pendown()
t.goto(250, -25)
t.goto(300, -25)
t.goto(300, 200)
t.goto(-150, 200)
t.goto(-175, 100)
t.goto(-300, 100)
t.goto(-300, -25)
t.goto(-250, -25)
t.end_fill()

# рисуем корпус

t.penup()
t.goto(-200, -75)
koleso(50)
t.penup()
t.goto(200, -75)
koleso(50)

# колеса

t.fillcolor("blue")
t.penup()
t.goto(-155, 100)
t.begin_fill()
t.pendown()
t.goto(-135, 185)
t.goto(285, 185)
t.goto(286, 100)
t.goto(-155, 100)
t.end_fill()

# окно

t.fillcolor("yellow")
t.penup()
t.goto(-280, 100)
t.begin_fill()
t.pendown()
t.goto(-280, 70)
t.goto(-300, 60)
t.goto(-300, 100)
t.goto(-280, 100)
t.end_fill()

# передняя фара

t.fillcolor("red")
t.penup()
t.goto(300, 120)
t.begin_fill()
t.pendown()
t.goto(300, 80)
t.goto(290, 80)
t.goto(290, 120)
t.goto(300, 120)
t.end_fill()

# задняя фара

t.penup()
while True:
    t.goto(-200, -200)
# зацикливаем, что бы не пропала картинка


