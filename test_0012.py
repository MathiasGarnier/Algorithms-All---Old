import uuid #For PlayerPosUUID function and PlayerUUID var
import random as rand #For rand.randrange() function.

playerUUID = uuid.uuid4() #Definie playerUUID to a random UUID

def Player(chance, rankByPower, rankPower): #Identifier for Player

    chance = rand.randrange(6) #Random result between 0 and 6 exclud
    rankByPower = int (Player().level) #ranByPower = level of this.getPlayer()
    rankPower = int (rankByPower - chance) #Convert to int the result of rankByPower - chance

    plUUID_NAME = int (Player().name) #Casting Player().name to an integer
    plUUID_RANK = int (Player().rankByPower) #Rank player with his level

    #player = [
     #   (plUUID_NAME, Player().playerUUID) #plUUID_NAME = casting of Player().name += rand uuid
      #  (plUUID_RANK, Player().rankPower)
    #]

def PlayerName(name):
    return name #Return player.getName (include an API for use this.getName)

def Level(level):
    return level

def PlayerPosUUID(uuid):
    uuid = int (uuid * 69)
    return uuid

#A finir un jour
