#include "coinitem.h"

CoinItem::CoinItem()
{

    setScale(0.4);
    coinSpinningSpeed = 120;

    coinImageSources.push_back(":/resource/img/coin1.png");
    coinImageSources.push_back(":/resource/img/coin2.png");
    coinImageSources.push_back(":/resource/img/coin3.png");
    coinImageSources.push_back(":/resource/img/coin4.png");
    coinImageSources.push_back(":/resource/img/coin3.png");
    coinImageSources.push_back(":/resource/img/coin2.png");


}

CoinItem::~CoinItem()
{

}

std::vector<std::string> CoinItem::getCoinImageSources()
{
    return coinImageSources;
}

int CoinItem::getCoinSpinningSpeed(){
    return coinSpinningSpeed;
}

