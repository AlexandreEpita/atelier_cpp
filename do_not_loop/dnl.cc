#include "dnl.hh"

size_t min_elt_length(const std::vector<std::string>& req)
{
    size_t res = std::min_element(req.begin(), req.end(), [](auto a, auto b) {
                     return a.size() < b.size();
                 })->size();
    return res;
}

size_t max_elt_length(const std::vector<std::string>& req)
{
    size_t res = std::min_element(req.begin(), req.end(), [](auto a, auto b) {
                     return a.size() > b.size();
                 })->size();
    return res;
}

size_t sum_elt_length(const std::vector<std::string>& req)
{
    return std::accumulate(
        req.begin(), req.end(), 0,
        [](int sum, const std::string& elem) { return sum + elem.size(); });
}

size_t count_elt(const std::vector<std::string>& req, const std::string& elt)
{
    return std::count(req.begin(), req.end(), elt);
}

size_t count_duplicate(const std::vector<std::string>& req)
{
    auto cpy = req;
    std::sort(cpy.begin(), cpy.end());
    auto endit = std::unique(cpy.begin(), cpy.end());
    return req.size() - (endit - cpy.begin());
}