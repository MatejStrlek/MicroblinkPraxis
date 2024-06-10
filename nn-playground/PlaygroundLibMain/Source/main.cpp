#include "ImageLoader.hpp"

#include <iostream>

int main( int argc, char ** argv )
{
    if ( argc != 2 )
    {
        std::cerr << "Usage: " << argv[ 0 ] << " <path to PNG file>\n";
        return 1;
    }

    try
    {
        ImageLoader loader( argv[ 1 ] );
        std::cout << "Image loaded successfully. Width: " << loader.getWidth() << ", Height: " << loader.getHeight()
                  << "\n";
    }
    catch ( const std::exception & e )
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
