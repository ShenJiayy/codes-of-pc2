#include <iostream>
#include <vector>

namespace noip {
    using Int = long long;
    constexpr Int MAX_N = 200000;

    struct Block {
        Int len, sum;
    };

    Int n;
    Int a[1+MAX_N];
    std::vector<Block> blocks {};

    Int floor_div(Int x, Int y) {
        if (x >= 0) return x/y;
        return -((-x+y-1)/y);
    }

    Int first_value(const Block &b) {
        return noip::floor_div(b.sum, b.len);
    }

    Int last_value(const Block &b) {
        return noip::floor_div(b.sum+b.len-1, b.len);
    }

    void main() {
        std::cin >> n;
        blocks.clear();
        for (Int i = 0; i < n; ++i) {
            Int x; std::cin >> x;
            a[i] = x-i;
            Block cur {1, a[i]};
            // 若相邻两块展开后仍有下降，则它们之间一定还要继续向右搬运，必须合并。
            while (!blocks.empty() && noip::last_value(blocks.back()) > noip::first_value(cur)) {
                cur.len += blocks.back().len;
                cur.sum += blocks.back().sum;
                blocks.pop_back();
            }
            blocks.push_back(cur);
        }
        Int answer = 0;
        Int prefix_a = 0, prefix_b = 0;
        Int pos = 0;
        for (Block block: blocks) {
            // 块内最终值是总和尽量平均后的非降序列。
            for (Int j = 0; j < block.len; ++j) {
                Int value = noip::floor_div(block.sum+j, block.len);
                prefix_a += a[pos];
                prefix_b += value;
                if (pos < n-1) answer += prefix_a-prefix_b;
                ++pos;
            }
        }
        std::cout << answer << std::endl;
    }
}

int main() {
    noip::Int T; std::cin >> T;
    while (T--) {
        noip::main();
    }
    return 0;
}