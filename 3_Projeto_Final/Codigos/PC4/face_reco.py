# -*- coding: utf-8 -*-
import face_recognition
import time
#from datetime import datetime
#from time import ctime

arq = open('lista_verificacao.txt','w')
his = open('historico.txt','a')

compare = '[True]'
f = '[False]'

# Banco de dados
known_image_01 = face_recognition.load_image_file("imagens/01.jpg")
known_image_02 = face_recognition.load_image_file("imagens/02.jpg")
known_image_03 = face_recognition.load_image_file("imagens/03.jpg")

# Foto tirada
unknown_image = face_recognition.load_image_file("imagens/unknown.jpg")

# Codificação do Banco de Dados
biden_encoding_01 = face_recognition.face_encodings(known_image_01)[0]
biden_encoding_02 = face_recognition.face_encodings(known_image_02)[0]
biden_encoding_03 = face_recognition.face_encodings(known_image_03)[0]

# Codificação foto tirada
try:
    unknown_encoding = face_recognition.face_encodings(unknown_image)[0]
except Exception:
    arq.write(f)


results_01 = face_recognition.compare_faces([biden_encoding_01], unknown_encoding)
results_02 = face_recognition.compare_faces([biden_encoding_02], unknown_encoding)
results_03 = face_recognition.compare_faces([biden_encoding_03], unknown_encoding)



if compare == str((results_01)):
    arq.write(compare)
    now = time.strftime("%c")
    his.write('\nUsuario 01 - ' + now)
elif compare == str((results_02)):
    arq.write(compare)
    now = time.strftime("%c")
#    aux = datetime.now().strftime('%Y-%m-%d %H:%M:%S\n')
    his.write('\nUsuario 02 - ' + now)
elif compare == str((results_03)):
    arq.write(compare)
    now = time.strftime("%c")
    his.write('\nUsuario 03 - ' + now)
else:
    arq.write(f)

his.close()
arq.close()
