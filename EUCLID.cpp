template<class num_t>
pair<num_t, num_t> euclid(num_t a, num_t b) {
    if (!b) return make_pair(1, 0);
    pair<num_t, num_t> r = euclid(b, a % b);
    return make_pair(r.second, r.first - a / b * r.second);
}