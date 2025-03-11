#include <iostream>
#include <string>
#include <vector>
#include <numeric>

class Product {
public:
    Product(const std::string& name, size_t priceCents, size_t quantity)
        : name(name), priceCents(priceCents), quantity(quantity) {}

    size_t getTotalPriceCents() const {
        return priceCents * quantity;
    }

    size_t getPriceAfterDiscount(size_t discountPercents) const {
        return (priceCents * (100 - discountPercents)) / 100;
    }

    std::string name;
    size_t priceCents; // Цена в копейках
    size_t quantity;
};

class Cart {
public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    const std::vector<Product>& getProducts() const {
        return products;
    }

    size_t calculateTotalCents() const {
        return std::accumulate(products.begin(), products.end(), static_cast<size_t>(0),
                               [](size_t total, const Product& product) {
                                   return total + product.getTotalPriceCents();
                               });
    }

private:
    std::vector<Product> products;
};

class PromoCode {
public:
    PromoCode(const std::string& code, size_t discountPercents)
        : code(code), discountPercents(discountPercents) {}

    size_t getDiscountPercents() const {
        return discountPercents;
    }

    std::string code;
    size_t discountPercents; // Скидка в процентах (целое число)
};

class Checkout {
public:
    Checkout(const Cart& cart, const PromoCode& promoCode)
        : cart(cart), promoCode(promoCode) {}

    void generateReceipt() {
        size_t totalCents = cart.calculateTotalCents();
        size_t discountAmount = (totalCents * promoCode.getDiscountPercents()) / 100;
        size_t finalAmount = totalCents - discountAmount;

        std::cout << "Receipt:" << std::endl;
        for (const auto& product : cart.getProducts()) {
            size_t priceAfterDiscount = product.getPriceAfterDiscount(promoCode.getDiscountPercents());
            std::cout << product.name << ": "
                      << product.priceCents / 100 << "." << product.priceCents % 100
                      << " * " << product.quantity
                      << " = " << product.getTotalPriceCents() / 100 << "." << product.getTotalPriceCents() % 100
                      << " (Discounted: " << (priceAfterDiscount * product.quantity) / 100 << "."
                      << (priceAfterDiscount * product.quantity) % 100 << ")" << std::endl;
        }
        std::cout << "Total before discount: " << totalCents / 100 << "." << totalCents % 100 << std::endl;
        std::cout << "Discount: " << discountAmount / 100 << "." << discountAmount % 100 << std::endl;
        std::cout << "Total after discount: " << finalAmount / 100 << "." << finalAmount % 100 << std::endl;
    }

private:
    Cart cart;
    PromoCode promoCode;
};

int main() {
    Cart cart;
    cart.addProduct(Product("Milk", 11000, 2)); // 110 рублей в копейках

    PromoCode promoCode("SAVE10", 10); // 10% discount

    Checkout checkout(cart, promoCode);
    checkout.generateReceipt();

    return 0;
}
