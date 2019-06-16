#pragma once
/**
 *  Elemento de la colección
 */
class ICollectible
{
protected:
    /*
     * No se permite instanciar ICollectible directamente
     */
    ICollectible();
public:
    virtual ~ICollectible();
};
