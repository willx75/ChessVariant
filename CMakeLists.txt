cmake_minimum_required(VERSION 3.13)
project(ChessVariants)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChessVariants main.cpp Plateau.cpp Plateau.h Cavalier.cpp Cavalier.h Piece.cpp Piece.h Pion.cpp Pion.h Position.cpp Position.h Roi.cpp Roi.h Reine.cpp Reine.h Tour.cpp Tour.h Fou.cpp Fou.h Partie.cpp Partie.h Couleur.cpp Couleur.h Deplacement.cpp Deplacement.h)