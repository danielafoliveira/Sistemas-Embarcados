# -*- coding: utf-8 -*-
import telegram
from telegram.ext import Updater, CommandHandler
import sys
import os 

# Define a few command handlers. These usually take the two arguments bot and
# update. Error handlers also receive the raised TelegramError object in error.
def start(bot, update):
    """Manda a mensagem quando o comando /start é enviado."""
    update.message.reply_text(
        'Olá, Sou o Gandalf Bot e estou aqui para ajudar você.!\n\n'
        'Como ainda sou um sistema de prototipagem e aceito apenas 3 usuarios'
        'Mande /cadastrar para cadastrar um novo usuario,'
        'Mande /abrir para abrir a porta sem verificação')

    
def cadastrar(bot, update):
    """Manda a mensagem quando o comando /cadastrar é enviado."""
    
    update.message.reply_text(
        'Ok, Como já fale eu tenho apenas 3 espaços para cadastro. Então informe em qual espaço deseja:\n'
        'Mande para mim o nome  do usuario da seguinte forma:\n/primeiro Fulano \n'
        'Agora agora irei tirar a foto, por favor sem oculos ou boné ')

def primeiro(bot,update):
    """ Cadastrando o primeiro usuario """
    
    usuario = update.message.text
    FILE = 'lista_cadastrados.txt'
    resposta_file = open(FILE,'a')
    resposta_file.write(usuario + "\n")

    aux = ('raspistill -w 640 -h 480 -q 75 -o ./imagens/01.jpg')
    os.system (aux)

    update.message.reply_text(
        'Nome registado\n\n'
        'Foto Tirada, se desejar ver a foto manda /verificarPrimeiro')

def segundo(bot,update):
    """ Cadastrando o primeiro usuario """
    
    usuario = update.message.text
    FILE = 'lista_cadastrados.txt'
    resposta_file = open(FILE,'a')
    resposta_file.write(usuario + "\n")

    aux = ('raspistill -w 640 -h 480 -q 75 -o ./imagens/02.jpg')
    os.system (aux)

    update.message.reply_text(
        'Nome registado\n\n'
        'Foto Tirada, se desejar ver a foto manda /verificarSegundo')

def terceiro(bot,update):
    """ Cadastrando o primeiro usuario """
    
    usuario = update.message.text
    FILE = 'lista_cadastrados.txt'
    resposta_file = open(FILE,'a')
    resposta_file.write(usuario + "\n")

    aux = ('raspistill -w 640 -h 480 -q 75 -o ./imagens/03.jpg')
    os.system (aux)

    update.message.reply_text(
        'Nome registado\n\n'
        'Foto Tirada, se desejar ver a foto manda /verificarTerceiro')
    
def verificaPrimeiro(bot,update):
    """ Manda a foto que foi cadastrada"""
    photo = open('/imagens/01.jpg','rb')
    update.sendPhoto(chat_id,photo)

    update.message.reply_text(
        'Foto do ultimo cadastro 01 foi enviada\n'
    )

def verificaSegundo(bot,update):
    """ Manda a foto que foi cadastrada"""
    photo = open('/imagens/02.jpg','rb')
    update.sendPhoto(chat_id,photo)

    update.message.reply_text(
        'Foto do ultimo cadastro 02 foi enviada\n'
    )
def verificaTerceiro(bot,update):
    """ Manda a foto que foi cadastrada"""
    update.sendPhoto(chat_id ,photo =open('imagens/03.jpg','rb'))

    update.message.reply_text(
        'Foto do ultimo cadastro 03 foi enviada\n'
    )

def ultimo(bot,update):
    """ Manda a foto que foi cadastrada"""
    update.send_photo(chat_id =chat_id,photo =open('imagens/unknown.jpg','rb'))

    update.message.reply_text(
        'Foto do ultima tentativa de log foi enviada\n'
    )


def abrir(bot,update):
    aux = ('sudo ./Cliente/cliente 127.0.0.1 8080 l')
    os.system(aux)
    update.message.reply_text(
        'Porta Aberta\n'
    )

def historico(bot,update):
    aux = ('sudo ./Cliente/cliente 127.0.0.1 8080 h')
    os.system(aux)
    hist = open('./Cliente/historico.txt','rb')
    aux = hist.read()
    hist.close()
    update.message.reply_text(
        'Historico de acesso:\n\n' + aux
    )

def main():
    """Start the bot."""
    # Create the EventHandler and pass it your bot's token.
    updater = Updater("")
    #bot = telegram.Bot(token='556806366:AAH9OIYZwwKapLkZrs7fYQU-NdUF2H9MuDc')
    print('Lendo...')
    # Get the dispatcher to register handlers
    dp = updater.dispatcher

    # on different commands - answer in Telegram
    dp.add_handler(CommandHandler("start", start))   
    dp.add_handler(CommandHandler("cadastrar", cadastrar))
    dp.add_handler(CommandHandler("primeiro", primeiro))
    dp.add_handler(CommandHandler("ultimo", ultimo))
    dp.add_handler(CommandHandler("verificaTerceiro",verificaTerceiro))
    dp.add_handler(CommandHandler("verificaSegundo",verificaSegundo))
    dp.add_handler(CommandHandler("verificaPrimeiro",verificaPrimeiro))
    dp.add_handler(CommandHandler("segundo",segundo))
    dp.add_handler(CommandHandler("terceiro",terceiro))
    dp.add_handler(CommandHandler("abrir", abrir))
    dp.add_handler(CommandHandler("historico", historico))

    # Start the Bot
    updater.start_polling()

    # Run the bot until you press Ctrl-C or the process receives SIGINT,
    # SIGTERM or SIGABRT. This should be used most of the time, since
    # start_polling() is non-blocking and will stop the bot gracefully.
    updater.idle()


if __name__ == '__main__':
    main()
