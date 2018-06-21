from telegram.ext import Updater, CommandHandler, MessageHandler, Filters
import logging
from telegram import User, Update
from subprocess import call
import system
import os

# Enable logging
logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                    level=logging.INFO)

logger = logging.getLogger(__name__)


# Define a few command handlers. These usually take the two arguments bot and
# update. Error handlers also receive the raised TelegramError object in error.
def start(bot, update):
    """Manda a mensagem quando o comando /start é enviado."""
    ID = update.message.chat_id
    FILE = str(ID) + '.txt'
    resposta_file = open(FILE,'w')
    resposta_file.write(str(ID) + "\n")

    #print ("%s %d", NOME_2,ID_2)
    update.message.reply_text(
        'Olá eu sou Gandalf\n\n'
        'Mande /registrar para registrar seu veículo ou /cancelar para parar de falar comigo.')


def main():
    """Start the bot."""
    # Create the EventHandler and pass it your bot's token.
    updater = Updater("556806366:AAH9OIYZwwKapLkZrs7fYQU-NdUF2H9MuDc")

    # Get the dispatcher to register handlers
    dp = updater.dispatcher

    # on different commands - answer in Telegram
    dp.add_handler(CommandHandler("start", start))
    dp.add_handler(CommandHandler("help", help))


    # Start the Bot
    updater.start_polling()

    # Run the bot until you press Ctrl-C or the process receives SIGINT,
    # SIGTERM or SIGABRT. This should be used most of the time, since
    # start_polling() is non-blocking and will stop the bot gracefully.
    updater.idle()


if __name__ == '__main__':
    main()
