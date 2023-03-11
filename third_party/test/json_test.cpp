///
/// Author: Alejandro Valencia
/// Update: 13 November, 2022
///

#include <fstream>
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <optional>

namespace
{

TEST(JsonTestBaseFixture, TestImportOfThirdPartyRepo)
{
    // Given
    std::optional<std::ifstream> input_file_("third_party/test/json_test_input.json");
    const std::string name("json_test_input");

    // Assert
    ASSERT_TRUE(input_file_.has_value());

    // When
    const auto input_data = nlohmann::json::parse(input_file_.value());

    // Expect
    EXPECT_TRUE(!input_data.empty());

    EXPECT_TRUE(input_data["name"] == name);

    EXPECT_TRUE(input_data["plain_object"]["pi"] == 3.14);

    EXPECT_TRUE(!input_data["vector_object"].empty());
    EXPECT_NEAR(input_data["vector_object"]["data"][0], 1, 0.01);

    EXPECT_TRUE(!input_data["plain_vector"].empty());
    EXPECT_NEAR(input_data["plain_vector"][2], 3, 0.01);
}

}  // namespace
