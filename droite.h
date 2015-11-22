#ifndef DROITE_H
#define DROITE_H
#include "vector2d.h"

/**
 * @brief The Droite class, a line that goes through an origin following a direction
 */
class Droite
{
    private:
        Vector2D o; /**< The origin of the line */
        Vector2D d; /**< The direction of the line, normalized */
    public:
        Droite();
        /**
         * @brief Droite
         * @param[in] p1 The origin of the line
         * @param[in] p2 The direction of the line
         */
        Droite(const Vector2D& p1,const Vector2D& p2) : o(p1), d(p2.normalized()) {}

        /**
         * @brief getIntersection Finds an intersection point with another Droite
         * @param[in] a The Droite to intersect
         * @param[out] point The intersection point
         * @return True if the Droites intersect, else false.
         */
        bool getIntersection(const Droite& a, Vector2D& point) const;

        /**
         * @brief Getter of o
         * @return A copy of the origin
         */
        Vector2D getO() const;

        /**
         * @brief Setter of o
         * @param[in] value The new value of o
         */
        void setO(const Vector2D& value);

        /**
         * @brief Getter of d
         * @return A copy of the direction
         */
        Vector2D getD() const;

        /**
         * @brief Setter of d
         * @param[in] value The new value of d
         */
        void setD(const Vector2D& value);
};

#endif // DROITE_H
