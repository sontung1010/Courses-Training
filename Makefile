.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge21 - Debug ]----------"
	@cd "Challenge21" && "$(MAKE)" -f  "Challenge21.mk"
clean:
	@echo "----------Cleaning project:[ Challenge21 - Debug ]----------"
	@cd "Challenge21" && "$(MAKE)" -f  "Challenge21.mk" clean
