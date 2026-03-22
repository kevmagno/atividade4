print("escolha dois numeros para fazer aritmetica")

num1 = int(input("escolha o primeiro numero: "))
num2 = int(input("escolha o segundo numero: "))

escolha = input("escolha qual operação fazer: + - * / ")

if escolha == '+':
    resultado = num1+num2

elif escolha == '-':
    resultado = num1-num2

elif escolha == '*':
    resultado = num1*num2

elif escolha == '/':
    resultado = num1/num2

else: 
    print("invalido. Escolha uma operação correspondente.")

print(f"o resultado de {num1} {escolha} {num2} é:", resultado)