//#include "game.hpp"
//
//void game::intCardSprites() {
//    deque<card>::iterator current = gameDeck.cards.begin();
//    while (current != gameDeck.cards.end()) {
//        switch (current->s) {
//            case suit::clubs:
//                switch(current->r){
//                    case rank::ace:
//                        current->cardSprite = &C0Sprite;
//                        break;
//                    case rank::two:
//                        current->cardSprite = &C2Sprite;
//                        break;
//                    case rank::three:
//                        current->cardSprite = &C3Sprite;
//                        break;
//                    case rank::four:
//                        current->cardSprite = &C4Sprite;
//                        break;
//                    case rank::five:
//                        current->cardSprite = &C5Sprite;
//                        break;
//                    case rank::six:
//                        current->cardSprite = &C6Sprite;
//                        break;
//                    case rank::seven:
//                        current->cardSprite = &C7Sprite;
//                        break;
//                    case rank::eight:
//                        current->cardSprite = &C8Sprite;
//                        break;
//                    case rank::nine:
//                        current->cardSprite = &C9Sprite;
//                        break;
//                    case rank::ten:
//                        current->cardSprite = &C10Sprite;
//                        break;
//                    case rank::jack:
//                        current->cardSprite = &C1Sprite;
//                        break;
//                    case rank::queen:
//                        current->cardSprite = &C11Sprite;
//                        break;
//                    case rank::king:
//                        current->cardSprite = &C12Sprite;
//                        break;
//                }
//                break;
//            case suit::diamonds:
//                switch (current->r) {
//                    case rank::ace:
//                        current->cardSprite = &D0Sprite;
//                        break;
//                    case rank::two:
//                        current->cardSprite = &D2Sprite;
//                        break;
//                    case rank::three:
//                        current->cardSprite = &D3Sprite;
//                        break;
//                    case rank::four:
//                        current->cardSprite = &D4Sprite;
//                        break;
//                    case rank::five:
//                        current->cardSprite = &D5Sprite;
//                        break;
//                    case rank::six:
//                        current->cardSprite = &D6Sprite;
//                        break;
//                    case rank::seven:
//                        current->cardSprite = &D7Sprite;
//                        break;
//                    case rank::eight:
//                        current->cardSprite = &D8Sprite;
//                        break;
//                    case rank::nine:
//                        current->cardSprite = &D9Sprite;
//                        break;
//                    case rank::ten:
//                        current->cardSprite = &D10Sprite;
//                        break;
//                    case rank::jack:
//                        current->cardSprite = &D1Sprite;
//                        break;
//                    case rank::queen:
//                        current->cardSprite = &D11Sprite;
//                        break;
//                    case rank::king:
//                        current->cardSprite = &D12Sprite;
//                        break;
//                }
//                break;
//            case suit::hearts:
//            switch(current->r){
//                case rank::ace:
//                    current->cardSprite = &H0Sprite;
//                    break;
//                case rank::two:
//                    current->cardSprite = &H2Sprite;
//                    break;
//                case rank::three:
//                    current->cardSprite = &H3Sprite;
//                    break;
//                case rank::four:
//                    current->cardSprite = &H4Sprite;
//                    break;
//                case rank::five:
//                    current->cardSprite = &H5Sprite;
//                    break;
//                case rank::six:
//                    current->cardSprite = &H6Sprite;
//                    break;
//                case rank::seven:
//                    current->cardSprite = &H7Sprite;
//                    break;
//                case rank::eight:
//                    current->cardSprite = &H8Sprite;
//                    break;
//                case rank::nine:
//                    current->cardSprite = &H9Sprite;
//                    break;
//                case rank::ten:
//                    current->cardSprite = &H10Sprite;
//                    break;
//                case rank::jack:
//                    current->cardSprite = &H1Sprite;
//                    break;
//                case rank::queen:
//                    current->cardSprite = &H11Sprite;
//                    break;
//                case rank::king:
//                    current->cardSprite = &H12Sprite;
//                    break;
//                } 
//                break;
//            case suit::spades:
//                switch(current->r){
//                    case rank::ace:
//                        current->cardSprite = &S0Sprite;
//                        break;
//                    case rank::two:
//                        current->cardSprite = &S2Sprite;
//                        break;
//                    case rank::three:
//                        current->cardSprite = &S3Sprite;
//                        break;
//                    case rank::four:
//                        current->cardSprite = &S4Sprite;
//                        break;
//                    case rank::five:
//                        current->cardSprite = &S5Sprite;
//                        break;
//                    case rank::six:
//                        current->cardSprite = &S6Sprite;
//                        break;
//                    case rank::seven:
//                        current->cardSprite = &S7Sprite;
//                        break;
//                    case rank::eight:
//                        current->cardSprite = &S8Sprite;
//                        break;
//                    case rank::nine:
//                        current->cardSprite = &S9Sprite;
//                        break;
//                    case rank::ten:
//                        current->cardSprite = &S10Sprite;
//                        break;
//                    case rank::jack:
//                        current->cardSprite = &S1Sprite;
//                        break;
//                    case rank::queen:
//                        current->cardSprite = &S11Sprite;
//                        break;
//                    case rank::king:
//                        current->cardSprite = &S12Sprite;
//                        break;
//
//                }
//                break;
//        }
//
//        current++;
//    }
//}