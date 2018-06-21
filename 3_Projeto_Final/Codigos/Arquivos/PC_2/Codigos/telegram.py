import sys
import time
import telepot
from telepot.loop import MessageLoop

def handle(msg):
    chat_id = msg['chat']['id']
    command =msg['text']
    print(command, chat_id)

#Inicio de conversa
    if command == 'Ola':
        bot.sendMessage(chat_id, 'Olá Mestre, o que você deseja? ')
    if command == 'oi':
        bot.sendMessage(chat_id, 'Olá Mestre, o que você deseja? ')
    if command == 'ola':
        bot.sendMessage(chat_id, 'Olá Mestre, o que você deseja? ')
    if command == 'Oi':
        bot.sendMessage(chat_id, 'Olá Mestre, o que você deseja? ')
# Cadastra novo usuario
    if command == 'Cadastrar':
        bot.sendMessage(chat_id, 'Informe o nome do usuario')

# Entrar
    if command == 'u'Abre'':
        os.system('abre.sh')

    if command == 'Negado':
        os.system('negado.sh')

# Deletar usuario


bot = telepot.Bot('556806366:AAH9OIYZwwKapLkZrs7fYQU-NdUF2H9MuDc')
MessageLoop(bot, handle).run_as_thread()
print ('lendo ...')

# Keep the program running.
while 1:
    time.sleep(10)
