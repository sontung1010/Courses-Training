import random
import turtle as t

from numpy import size

tim = t.Turtle()
# direction = [0, 90, 180, 270]
# tim.pensize(15)
tim.speed("fastest")
t.colormode(255)
# tim.colormode(255)

# def draw_shape(num_sides):
#     for _ in range(num_sides):
#         angle = 360/num_sides
#         tim.forward(100)
#         tim.right(angle)

# for shape_side_n in range(3, 11):
#     tim.color(random.choice(colors))
#     draw_shape(shape_side_n)

def random_color():
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    color = (r, g, b)
    return color

# for _ in range(100000000):
#     tim.color(random_color())
#     tim.forward(30)
#     tim.setheading(random.choice(direction))

def draw_spirograph(size_of_gap):
    for _ in range(int(360/size_of_gap)):
        tim.color(random_color())
        tim.circle(100)
        tim.setheading(tim.heading()+10)

draw_spirograph(5)

screen = t.Screen()
screen.exitonclick()