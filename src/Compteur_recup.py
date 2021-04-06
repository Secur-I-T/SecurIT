import firebase_admin
from firebase_admin import credentials, firestore
from datetime import datetime

## Initialisation du sdk
cred = credentials.Certificate("securit2-compteur.json")
firebase_admin.initialize_app(cred)

## Initialisation firestore instance
db = firestore.client()

## add data live
    dataLive = {
        u'counterLive' : str(total_person),
    }
db.collection(u'Compteur').document(u'val_compt').set(dataLive)
