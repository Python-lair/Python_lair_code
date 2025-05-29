import random
import string

pass_len = input("Введите длину вашего пароля ")

id_str = ''.join(random.choices(string.ascii_uppercase + string.digits, k = int(pass_len)))

print(id_str)