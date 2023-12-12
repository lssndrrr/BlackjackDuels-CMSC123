//#include "game.hpp"
//#include "header.hpp"
//
//characterList::characterList(){
//    head = tail = NULL;
//    for(int c = static_cast<int>(chr::jackblack); c <= static_cast<int>(chr::jade); c++){
//        addCharacter(c);
//    }
//}
//
//void characterList::addCharacter(int c){
//    character* newChar = new character;
//    newChar->name = static_cast<chr>(c);
//    newChar->next = NULL;
//    if(head == NULL){
//        head = tail = newChar;
//    } else{
//        tail->next = newChar;
//        tail = newChar;
//    }
//}
//
//void character::useAbility(){
//    switch(name){
//        case chr::jackblack:
//            // do ability here
//        break;
//        case chr::jake:
//            // do ability here
//        break;
//        case chr::jackson:
//            // do ability here
//        break;
//        case chr::jade:
//            // do ability here;
//        break;
//        default:           break;
//    }
//}
//
//string characterList::getCharacter(chr c){
//    switch(c){
//        case chr::jackblack:    return "Jack Black";
//        case chr::jake:         return "Jake Blake";
//        case chr::jackson:      return "Jackson Blackson";
//        case chr::jade:         return "Jade Blade";
//        default:                return "ERROR";
//    }
//}
//
//string characterList::getCharDesc(chr c){
//    switch(c){
//        case chr::jackblack:
//            return "A pickpocket who picked the pockets of the wrong crowd, now fighting for another chance at life.";
//        case chr::jake:
//            return "A bully whose victims got revenge. He wishes for the chance to correct his wrongs.";
//        case chr::jackson:
//            return "A gambler who bet other people's stuff.";
//        case chr::jade:
//            return "A doctor who operated on his patients wrongly.";
//        default:
//            return "ERROR";
//    }
//}
//
//string characterList::getAbDesc(chr c){
//    switch(c){
//        case chr::jackblack:
//            return "Able to steal the card of an opponent.";
//        case chr::jake:
//            return "Ability to double the stakes. Twice the damage for those who lose the round.";
//        case chr::jackson:
//            return "Ability to restart turn.";
//        case chr::jade:
//            return "Ability to change one of his cards to another random denomination.";
//        default:
//            return "ERROR";
//    }
//}
//
//void characterList::displayCharacters(){
//    character* current = head;
//    while(current != NULL){
//        cout << getCharacter(current->name) << endl << getCharDesc(current->name) << endl << getAbDesc(current->name) << endl;
//        current = current->next;
//    }
//}