class HandleSlider {
    constructor(slider) {
        this.diapo = document.querySelectorAll(slider);
        this.current = 0;
        this.howmanySlide = this.diapo.length;
        this.slideInit();
    }

    slideInit() {
        this.diapo[this.current].classList.add("show");
        this.handleMove();
    }

    nextSlide() {
        this.diapo[this.current].classList.remove("show");
        if (this.current === this.howmanySlide - 1) {
            this.current = 0;
        }
        else {
            this.current = this.current + 1;
        }
        this.diapo[this.current].classList.add("show");
    }

    previousSlide() {
        this.diapo[this.current].classList.remove("show");

        if (this.current === 0) {
            this.current = this.howmanySlide - 1;
        }
        else {
            this.current = this.current - 1;
        }
        this.diapo[this.current].classList.add("show");
    }

    handleMove() {
        document.querySelector("#next").addEventListener("click", () => this.nextSlide());
        document.querySelector("#previous").addEventListener("click", () => this.previousSlide());
    }
}

const diaposi = new HandleSlider("#currentSlide img");
