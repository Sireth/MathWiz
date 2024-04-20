#pragma once

#include <memory>
// #include <optional>
#include <string>
#include <boost/optional/optional.hpp>
#include <vector>

namespace sql
{
	struct Ast;

	struct String;
	struct Number;
	struct Boolean;

	struct BinaryOperator;

	struct AddOperator;
	struct SubtractOperator;
	struct MultiplyOperator;
	struct DivideOperator;
	struct GreaterOperator;
	struct LessOperator;
	struct EqualOperator;
	struct NotEqualOperator;
	struct GreaterEqualOperator;
	struct LessEqualOperator;
	struct InOperator;
	struct AndOperator;
	struct OrOperator;

	enum class AstType
	{
		name,
		string,
		number,
		boolean,
		binary_operator,
	};

	struct AstVisitor {
		virtual ~AstVisitor() = default;

		virtual void visit(std::shared_ptr<Ast> ast) = 0;

		virtual void visit(std::shared_ptr<BinaryOperator> ast) = 0;

		virtual void visit(std::shared_ptr<Number> ast) = 0;

		virtual void visit(std::shared_ptr<Boolean> ast) = 0;

		virtual void visit(std::shared_ptr<String> ast) = 0;

		virtual void visit(const std::shared_ptr<AddOperator> & ast) = 0;

		virtual void visit(std::shared_ptr<SubtractOperator> ast) = 0;

		virtual void visit(std::shared_ptr<MultiplyOperator> ast) = 0;

		virtual void visit(std::shared_ptr<DivideOperator> ast) = 0;

		virtual void visit(std::shared_ptr<GreaterOperator> ast) = 0;

		virtual void visit(std::shared_ptr<LessOperator> ast) = 0;

		virtual void visit(std::shared_ptr<EqualOperator> ast) = 0;

		virtual void visit(std::shared_ptr<NotEqualOperator> ast) = 0;

		virtual void visit(std::shared_ptr<GreaterEqualOperator> ast) = 0;

		virtual void visit(std::shared_ptr<LessEqualOperator> ast) = 0;

		virtual void visit(std::shared_ptr<InOperator> ast) = 0;

		virtual void visit(std::shared_ptr<AndOperator> ast) = 0;

		virtual void visit(std::shared_ptr<OrOperator> ast) = 0;

	};



	struct Ast
	{
		AstType type;

		explicit Ast(AstType type);

		virtual ~Ast() = default;
	};

	struct String : public Ast
	{
		std::string value;

		String(const std::string &value);
	};

	struct Number : public Ast
	{
		int value;

		explicit Number(int value);
	};

	struct Boolean : public Ast {
		bool value;
		explicit Boolean(bool value);
	};

	struct BinaryOperator : public Ast {
		enum Type {
			add,
			sub,
			mul,
			div,

			gr,
			le,
			eq,
			gr_eq,
			le_eq,
			n_eq,

			in,

			_and,
			_or
		};

		std::shared_ptr<Ast> left;
		std::shared_ptr<Ast> right;
		Type op;

		BinaryOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right, Type op);

	};

	struct AddOperator : public BinaryOperator {
		explicit AddOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	};
	struct SubtractOperator : public BinaryOperator {
		explicit SubtractOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	};

	struct MultiplyOperator : public BinaryOperator {
		explicit MultiplyOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	};

	struct DivideOperator : public BinaryOperator {
		explicit DivideOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	};

	struct GreaterOperator : public BinaryOperator {
		explicit GreaterOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	};

	struct LessOperator : public BinaryOperator {
		explicit LessOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	};

	struct EqualOperator : public BinaryOperator {
		explicit EqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	};
	struct NotEqualOperator : public BinaryOperator {
		explicit NotEqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

	};
	struct GreaterEqualOperator : public BinaryOperator {
		explicit GreaterEqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

	};
	struct LessEqualOperator : public BinaryOperator {
		explicit LessEqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

	};
	struct InOperator : public BinaryOperator {
		explicit InOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

	};
	struct AndOperator : public BinaryOperator {
		explicit AndOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

	};
	struct OrOperator : public BinaryOperator {
		explicit OrOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

	};

	template <class AstClass>
	inline std::shared_ptr<AstClass> As(std::shared_ptr<Ast> ast)
	{
		return std::dynamic_pointer_cast<AstClass>(ast);
	}

	struct EvalVisitor : AstVisitor {

		std::shared_ptr<Ast> result;

		void visit(std::shared_ptr<Ast> ast) override;

		void visit(std::shared_ptr<Number> ast) override;

		void visit(std::shared_ptr<BinaryOperator> ast) override;

		void visit(std::shared_ptr<Boolean> ast) override;

		void visit(std::shared_ptr<String> ast) override;

		void visit(const std::shared_ptr<AddOperator> &ast) override;

		void visit(std::shared_ptr<SubtractOperator> ast) override;

		void visit(std::shared_ptr<MultiplyOperator> ast) override;

		void visit(std::shared_ptr<DivideOperator> ast) override;

		void visit(std::shared_ptr<GreaterOperator> ast) override;

		void visit(std::shared_ptr<LessOperator> ast) override;

		void visit(std::shared_ptr<EqualOperator> ast) override;

		void visit(std::shared_ptr<NotEqualOperator> ast) override;

		void visit(std::shared_ptr<GreaterEqualOperator> ast) override;

		void visit(std::shared_ptr<LessEqualOperator> ast) override;

		void visit(std::shared_ptr<InOperator> ast) override;

		void visit(std::shared_ptr<AndOperator> ast) override;

		void visit(std::shared_ptr<OrOperator> ast) override;

		template<typename T>
		boost::optional<std::pair<T,T>> getValues(const std::shared_ptr<BinaryOperator> &ast);
	};

	template<>
	inline boost::optional<std::pair<int, int>> EvalVisitor::getValues(const std::shared_ptr<BinaryOperator> &ast) {
		visit(As<Ast>(ast->left));
		if(result->type == AstType::number) {
			const auto left = As<Number>(result)->value;
			visit(As<Ast>(ast->right));
			if (result->type != AstType::number) {
				throw std::runtime_error("Right operand is not a number!");
			}
			const auto right = As<Number>(result)->value;
			return std::make_pair(left, right);
		}
		return boost::none;
	}

	template<>
	inline boost::optional<std::pair<std::string, std::string>> EvalVisitor::getValues(const std::shared_ptr<BinaryOperator> &ast) {
		visit(As<Ast>(ast->left));
		if(result->type == AstType::string) {
			const auto left = As<String>(result)->value;
			visit(As<Ast>(ast->right));
			if (result->type != AstType::string) {
				throw std::runtime_error("Right operand is not a number!");
			}
			const auto right = As<String>(result)->value;
			return std::make_pair(left, right);
		}
		return boost::none;
	}

	template<>
	inline boost::optional<std::pair<bool, bool>> EvalVisitor::getValues(const std::shared_ptr<BinaryOperator> &ast) {
		visit(As<Ast>(ast->left));
		if(result->type == AstType::boolean) {
			const auto left = As<Boolean>(result)->value;
			visit(As<Ast>(ast->right));
			if (result->type != AstType::boolean) {
				throw std::runtime_error("Right operand is not a number!");
			}
			const auto right = As<Boolean>(result)->value;
			return std::make_pair(left, right);
		}
		return boost::none;
	}

	std::shared_ptr<Ast> new_name(std::string value);
	std::shared_ptr<Ast> new_string(const std::string &value);
	std::shared_ptr<Ast> new_number(int value);
	std::shared_ptr<Ast> new_binary_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right, BinaryOperator::Type type);
	std::shared_ptr<Ast> new_add_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	std::shared_ptr<Ast> new_subtract_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	std::shared_ptr<Ast> new_multiply_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	std::shared_ptr<Ast> new_divide_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	std::shared_ptr<Ast> new_greater_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	std::shared_ptr<Ast> new_less_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	std::shared_ptr<Ast> new_equal_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	std::shared_ptr<Ast> new_not_equal_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	std::shared_ptr<Ast> new_greater_equal_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	std::shared_ptr<Ast> new_less_equal_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	std::shared_ptr<Ast> new_in_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	std::shared_ptr<Ast> new_and_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
	std::shared_ptr<Ast> new_or_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);


} // namespace sql