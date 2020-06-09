#ifndef CVECTOR2F
#define CVECTOR2F

#include <Common/FileIO/IInputStream.h>
#include <Common/FileIO/IOutputStream.h>
#include <cmath>

class CVector2f
{
public:
    float X = 0.0f;
    float Y = 0.0f;

    constexpr CVector2f() = default;
    constexpr CVector2f(float XY) : X{XY}, Y{XY} {}
    constexpr CVector2f(float X_, float Y_) : X{X_}, Y{Y_} {}
    explicit CVector2f(IInputStream& rInput);
    void Write(IOutputStream& rOutput) const;

    [[nodiscard]] float Magnitude() const {
        return std::sqrt(SquaredMagnitude());
    }
    [[nodiscard]] float SquaredMagnitude() const {
        return Dot(*this);
    }
    [[nodiscard]] CVector2f Normalized() const {
        return *this / Magnitude();
    }
    [[nodiscard]] constexpr float Dot(const CVector2f& other) const {
        return (X * other.X) + (Y * other.Y);
    }

    [[nodiscard]] constexpr CVector2f operator+(const CVector2f& other) const {
        return {X + other.X, Y + other.Y};
    }
    [[nodiscard]] constexpr CVector2f operator-(const CVector2f& other) const {
        return {X - other.X, Y - other.Y};
    }
    [[nodiscard]] constexpr CVector2f operator*(const CVector2f& other) const {
        return {X * other.X, Y * other.Y};
    }
    [[nodiscard]] constexpr CVector2f operator/(const CVector2f& other) const {
        return {X / other.X, Y / other.Y};
    }

    constexpr void operator+=(const CVector2f& other) {
        *this = *this + other;
    }
    constexpr void operator-=(const CVector2f& other) {
        *this = *this - other;
    }
    constexpr void operator*=(const CVector2f& other) {
        *this = *this * other;
    }
    constexpr void operator/=(const CVector2f& other) {
        *this = *this / other;
    }

    [[nodiscard]] constexpr CVector2f operator+(const float other) const {
        return {X + other, Y + other};
    }
    [[nodiscard]] constexpr CVector2f operator-(const float other) const {
        return {X - other, Y - other};
    }
    [[nodiscard]] constexpr CVector2f operator*(const float other) const {
        return {X * other, Y * other};
    }
    [[nodiscard]] constexpr CVector2f operator/(const float other) const {
        return {X / other, Y / other};
    }

    constexpr void operator+=(const float other) {
        *this = *this + other;
    }
    constexpr void operator-=(const float other) {
        *this = *this - other;
    }
    constexpr void operator*=(const float other) {
        *this = *this * other;
    }
    constexpr void operator/=(const float other) {
        *this = *this / other;
    }

    [[nodiscard]] constexpr bool operator==(const CVector2f& other) const {
        return X == other.X && Y == other.Y;
    }
    [[nodiscard]] constexpr bool operator!=(const CVector2f& other) const {
        return !operator==(other);
    }

    [[nodiscard]] constexpr CVector2f operator-() const {
        return {-X, -Y};
    }

    [[nodiscard]] constexpr float& operator[](long Index) {
        return (&X)[Index];
    }
    [[nodiscard]] constexpr const float& operator[](long Index) const {
        return (&X)[Index];
    }

    // Static Members
    static const CVector2f skZero;
    static const CVector2f skOne;
    static const CVector2f skUp;
    static const CVector2f skRight;
    static const CVector2f skDown;
    static const CVector2f skLeft;
};

#endif // CVECTOR2F
