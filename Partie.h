//
// Created by will2 on 05/01/2019.
//

#ifndef CHESSVARIANTS_PARTIE_H
#define CHESSVARIANTS_PARTIE_H

#include "Piece.h"

class Partie {

public:

    Plateau();

    Plateau(std::list<Deplacement *> deplacement);

    Plateau(const Plateau &plateau);


    ~Plateau();


    /**
     * Returns all possible moves for a given coulour of the board. Internaly this methode
     * calls the virtual getPossobleMoves methode of each chesman, whitch holds the
     * individual game logic of each chesman
     * @param  colour The colour for for witch this methode will be applied
     * @return        All possible moves for a given colour
     */
    std::list<Deplacement> getAllPossibleMoves(Piece::Couleur couleur) const;

    /**
     * Returns all previous moves in a list of move pointer
     */
    std::list<Deplacement *> UndoDeplacement() const;

    /**
     * Returns the pointer of a chesman at a given position. Is nullptr if there is
     * no chessman at the board
     */
    Piece *getPiece(Position) const;

    /**
     * This methode applys a move to the chessboard.  To do so it checks if the move
     * is valid by looking the move in all possible moves up. This methode is also
     * responsible to check if a move is a casteling. If so the movetype of the given
     * move will be changed. It also checks if the player is still in check after the
     * move. After a succesful move the current colour of the board will be
     * changed.
     *
     * @param  move The move whitch will be applyed
     * @return      Returns true if the application of the move was succesful
     */
    bool applyMove(Deplacement *deplacement);

    /**
     * Promotes the figure at the target of a given move to the given new figure type.
     * The responsibility to check if a move is a promotion is up to the controller.
     * The old figure will be stored in the captured chessman list to enable undo.
     * @param move The actual move for the promotion
     * @param type The figure type to whitch the figure will be promoted

    void applyPromotion(Move *move, Chessman::FigureType type);

    /**
     * Undoes the last move. It is also responcible to detect casteling and promotions.
     * The last move will be deleted by this methode
     */
    void undoLastMove();

    /**
     * Checks if its check by checking if one possible move can capture the king.
     * @return True if the current player is in check
     */
    bool isCheck() const;

    /**
     * checks if its checkmate by applying each possible move to a copyed board
     * and check if its still check after the move
     * @return True if the current player is in checkmate
     */
    bool isCheckmate() const;

    /**
     * Checks if the game is a draw. The following draws are supported:
     *    - if there is no possible move for the current player
     * @return True if the game is a draw
     */
    bool isDraw() const;

    /**
     * For a given move this function looks up if this move is a promotion
     * @param  move The move that is involved in this checking
     * @return      True if its a promotion
     */
    bool isPromotion(Deplacement *move) const;

private:
    Piece ***board;
    Piece::Couleur currentColour;

    /**
     * Cree un nouveau plateau et l'initialise avec les postions de depart de chaque piece
     * @return un pointeur to the fresh initialized chessboard
     */
    Piece ***start();

    /**
     * Does the actual move action to avoid code redundancy
     * @param move The move that will be applyed
     */
    void move(Deplacement *deplacement);

    /**
     * changes the current colour of the board.
     */
    void changeCurrentColour();

    std::list<Piece *> capturedChessmen;
    std::list<Deplacement *> previousMoves;

};

#endif //CHESSVARIANTS_PARTIE_H
