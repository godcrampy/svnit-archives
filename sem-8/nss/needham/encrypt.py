from cryptography.fernet import Fernet
import json

class Cipher:
    def __init__(self, key):
        self.f = Fernet(key.encode('utf-8'))

    def encrypt(self, obj):
        return self.f.encrypt(json.dumps(obj).encode('utf-8')).decode()

    def decrypt(self, txt):
        return json.loads(self.f.decrypt(txt.encode('utf-8')))


def generate_key():
    return Fernet.generate_key().decode()