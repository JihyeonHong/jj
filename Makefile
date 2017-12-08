DIRS = lib source
.PHONY: clean

all:
<<<<<<< HEAD
	@for d in &(DIRS); \
	do \
		$(MAKE) -C $$d; \
	done

clean:
	@for d in &(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done
=======
  @for d in $(DIRS); \
  do \
    $(MAKE) -C $$d; \
  done
  
clean:
  @for d in $(DIRS); \
  do \
    $(MAKE) -C $$d clean; \
  done
>>>>>>> f1161c7a11adf3e583d54813c3a2a84d1871677d
