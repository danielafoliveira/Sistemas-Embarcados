import os
import face_recognition

foto1 = 'imagens/biden.jpg'

imagem_conhecida = face_recognition.load_image_file ( foto1)
unknown_image = face_recognition.load_image_file ( "imagens/desconhecido.jpg" )

biden_encoding = face_recognition.face_encodings ('known_image') [ 0 ]
unknown_encoding = face_recognition.face_encodings ('imagem_desconhecida') [ 0 ]

results = face_recognition.compare_faces ([biden_encoding], unknown_encoding)
printf(results)
