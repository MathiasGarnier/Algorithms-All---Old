import numbers
from types import SimpleNamespace

from Exception import InputError

class Client(object):

    clientList = []

    def __init__(self, clientID):

        if not isinstance(clientID, numbers.Real):
            raise ValueError("ClientID must be a Real number.")

        if self.__class__.clientList.count(clientID) >= 1:
            raise InputError("It seems the clientID you have chosen is used.")

        self.clientID = clientID
        self.__class__.clientList.append(clientID)

    def __del__(self):

        del self.clientList[:]

class ClientAccount(object):

    def __init__(self):

        self.sold = 0

    def getSold(self):

        return self.sold

    def addMoney(self, money):

        if not isinstance(money, numbers.Real):
            raise ValueError("Money must be a Real number.")

        self.sold += money

    def __del__(self):

        self.sold = None

def getClientList():

    instances = []
    for instance in Client.clientList:
        instances.append(instance)

    return instances

def link(client, clientAccount):

    if not isinstance(client, Client) and not isinstance(clientAccount, ClientAccount):
        raise ValueError("Client or ClientAccount parameter should be instance from Client or ClientAccount.")

    obj = SimpleNamespace()

    setattr(obj, "clientID", client.clientID)
    setattr(obj, "sold", clientAccount.sold)
    #@TODO NOTE Don't forget to add new attribute if Client or ClientAccount constructor change.

    return obj