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

    double getPriceAfterDiscount(double discount) const {
        return priceCents * (1 - discount) / 100.0; // Конвертация в рубли
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
    PromoCode(const std::string& code, double discount)
        : code(code), discount(discount) {}

    double getDiscount() const {
        return discount;
    }

    std::string code;
    double discount;
};

class Checkout {
public:
    Checkout(const Cart& cart, const PromoCode& promoCode)
        : cart(cart), promoCode(promoCode) {}

    void generateReceipt() {
        size_t totalCents = cart.calculateTotalCents();
        double discountAmount = totalCents * promoCode.getDiscount();
        double finalAmount = totalCents - discountAmount;

        std::cout << "Receipt:" << std::endl;
        for (const auto& product : cart.getProducts()) {
            double priceAfterDiscount = product.getPriceAfterDiscount(promoCode.getDiscount());
            std::cout << product.name << ": "
                      << product.priceCents / 100.0 << " * " << product.quantity
                      << " = " << product.getTotalPriceCents() / 100.0 << " (Discounted: "
                      << priceAfterDiscount * product.quantity << ")" << std::endl;
        }
        std::cout << "Total before discount: " << totalCents / 100.0 << std::endl;
        std::cout << "Discount: " << discountAmount / 100.0 << std::endl;
        std::cout << "Total after discount: " << finalAmount / 100.0 << std::endl;
    }

private:
    Cart cart;
    PromoCode promoCode;
};

int main() {
    Cart cart;
    cart.addProduct(Product("Milk", 11000, 2)); // 110 рублей в копейках

    PromoCode promoCode("SAVE10", 0.10); // 10% discount

    Checkout checkout(cart, promoCode);
    checkout.generateReceipt();

    return 0;
}
